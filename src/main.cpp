/*
Copyright (c) 2023 Bert Melis. All rights reserved.

This work is licensed under the terms of the MIT license.  
For a copy, see <https://opensource.org/licenses/MIT> or
the LICENSE file.
*/

#include <Arduino.h>

#include <espMqttManager.h>
#include <HassDiscovery.h>

#define BASETOPIC "vhs100"
#define DEVICEID "deviceid1"
#define DEVICENAME "devicename"
#define DEVICEICON "deviceicon"
constexpr int8_t ledPin = LED_BUILTIN;

espMqttManagerHelpers::Uptime uptime;
constexpr uint32_t statsInterval = 60000UL;
size_t sessionSetupStep = 0;

void onSetupSession() {
  if (ESP.getMaxAllocHeap() < 16384UL) {
    return;
  }

  switch (sessionSetupStep) {
  case 0:
    // subscribe to update channel
    if (espMqttManager::mqttClient.subscribe(BASETOPIC "/" DEVICEID "/$system/update", 0)) {
      ++sessionSetupStep;
    }
    return;
  case 1:
    // wait for suback
    return;
  case 2:
  {
    HassDiscovery::Sensor device(DEVICEID, DEVICENAME);
    device.setSystem();
    device.json()[HADISCOVERY_UNIT_OF_MEASUREMENT] = "dBm";
    device.json()[HADISCOVERY_ICON] = "mdi:wifi";
    if (!device.create("signal", "Signal strength") ||
        !espMqttManager::mqttClient.publish(device.topic(), 1, true, device.payload())) {
      return;
    }
  }
  ++sessionSetupStep;
  [[fallthrough]];
  case 3:
  {
    HassDiscovery::Sensor device(DEVICEID, DEVICENAME);
    device.setSystem();
    device.json()[HADISCOVERY_UNIT_OF_MEASUREMENT] = "b";
    device.json()[HADISCOVERY_ICON] = "mdi:memory";
    if (!device.create("memory", "Free memory") ||
        !espMqttManager::mqttClient.publish(device.topic(), 1, true, device.payload())) {
      return;
    }
  }
  ++sessionSetupStep;
  [[fallthrough]];
  case 4:
  {
    HassDiscovery::Sensor device(DEVICEID, DEVICENAME);
    device.setSystem();
    device.json()[HADISCOVERY_UNIT_OF_MEASUREMENT] = "s";
    device.json()[HADISCOVERY_ICON] = "mdi:timer-check-outline";
    if (!device.create("uptime", "Uptime") ||
        !espMqttManager::mqttClient.publish(device.topic(), 1, true, device.payload())) {
      return;
    }
  }
  ++sessionSetupStep;
  [[fallthrough]];
  case 5:
  {
    /*
    HassDiscovery::Sensor device(DEVICEID, DEVICENAME);
    device.json()[HADISCOVERY_UNIT_OF_MEASUREMENT] = "unit";
    device.json()[HADISCOVERY_ICON] = "mdi:icon";
    if (!device.create("codename", "friendlyname") ||
        !espMqttManager::mqttClient.publish(device.topic(), 1, true, device.payload())) {
      return;
    }
    */
  }
  ++sessionSetupStep;
  [[fallthrough]];
  case 6:
  {
    sessionSetupStep = 0;
    espMqttManager::sessionReady();
    return;
  }
  default:
    return;
  }
}

void sendStats() {
  char payload[18] = {'\0'};  // uptime: 18446744073709551615 / 1000, signal: 100, heap: 250000
  snprintf(payload, sizeof(payload), "%" PRIu64, uptime.getUptime() / 1000);
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/uptime", 0, false, payload);
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/uptimereadable", 0, false, uptime.getUptimeStr());
  snprintf(payload, sizeof(payload), "%i", WiFi.RSSI());
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/signal", 0, false, payload);
  snprintf(payload, sizeof(payload), "%lu", ESP.getFreeHeap());
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/memory", 0, false, payload);
}

void onWiFiConnected() {
  Serial.print("WiFi connected\n");
}

void onWiFiDisconnected() {
  Serial.print("WiFi disconnected\n");
}

void onMqttConnected() {
  Serial.print("MQTT connected\n");
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/status", 1, true, "online");
}

void onMqttDisconnected(espMqttClientTypes::DisconnectReason reason) {
  Serial.printf("MQTT disconnected: %u\r\n", static_cast<uint8_t>(reason));
}

void onDisconnected() {
  ESP.restart();
}

void onSubscribe(uint16_t packetId, const espMqttClientTypes::SubscribeReturncode* returncodes, size_t len) {
  (void) packetId;
  (void) len;
  if (returncodes[0] != espMqttClientTypes::SubscribeReturncode::FAIL) {
    ++sessionSetupStep;
  } else {
    abort();
  }
}

void onMqttMessage(const espMqttClientTypes::MessageProperties& properties, const char* topic, const uint8_t* payload, size_t len, size_t index, size_t total) {
  (void) properties;
  if (strcmp(topic, BASETOPIC "/" DEVICEID "/$system/update") == 0) {
    Serial.printf("update: %zu - %zu/%zu\n", len, index + len, total);
    espMqttManagerHelpers::handleUpdate(payload, len, index, total);
    if (espMqttManagerHelpers::updated) {
      espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/status", 1, true, "reboot");
      espMqttManager::disconnect();
    }
    return;
  }
}

void setup() {
  Serial.begin(115200);
  delay(2500);

  espMqttManager::setup();
  espMqttManager::mqttClient.setClientId(DEVICEID)
                            .setWill(BASETOPIC "/" DEVICEID "/$system/status", 1, true, "offline")
                            .onMessage(onMqttMessage)
                            .onSubscribe(onSubscribe);
  WiFi.setHostname(DEVICEID);
  espMqttManager::start();
}

void loop() {
  static uint32_t currentMillis = 0;
  static uint32_t lastStats = 0;
  currentMillis = millis();
  if (espMqttManager::isConnected()) {
    if (currentMillis - lastStats > statsInterval) {
      lastStats = currentMillis;
      Serial.print("Sending statistics\n");
      sendStats();
    }
  }
  espMqttManager::loop();
}
