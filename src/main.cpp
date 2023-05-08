/*
Copyright (c) 2023 Bert Melis. All rights reserved.

This work is licensed under the terms of the MIT license.  
For a copy, see <https://opensource.org/licenses/MIT> or
the LICENSE file.
*/

#include <Arduino.h>

#include <ArduinoJson.h>
#include <espMqttManager.h>

#include "HassDiscoveryAbbreviations.h"
#include "Version.h"

#define BASETOPIC "basetopic"
#define DEVICEID "deviceid"
#define DEVICENAME "device name"
#define DEVICEICON "mdi:connection"

uint32_t lastStats = 0;
espMqttManagerHelpers::Uptime uptime;
const uint32_t statsInterval = 60000;

void onSetupSession() {
  espMqttManager::mqttClient.subscribe(BASETOPIC "/" DEVICEID "/$system/update", 0);
  {
    // uptime statistic
    StaticJsonDocument<512> jsonDoc;
    jsonDoc[DISCOVERY_NAME] = DEVICENAME " uptime";
    jsonDoc[DISCOVERY_UNIQUE_ID] = DEVICEID "uptime";
    jsonDoc[DISCOVERY_BASETOPIC] = BASETOPIC "/" DEVICEID;
    jsonDoc[DISCOVERY_STATE_TOPIC] = "~/$system/uptime";
    jsonDoc[DISCOVERY_OPTIMISTIC] = false;
    JsonObject availability  = jsonDoc[DISCOVERY_AVAILABILITY].createNestedObject();
    availability[DISCOVERY_TOPIC] = "~/$system/status";
    availability[DISCOVERY_PAYLOAD_AVAILABLE] = "online";
    availability[DISCOVERY_PAYLOAD_NOT_AVAILABLE] = "offline";
    jsonDoc[DISCOVERY_AVAILABILITY_MODE] = "latest";
    jsonDoc[DISCOVERY_ICON] = "mdi:timer-check-outline";
    JsonObject device  = jsonDoc.createNestedObject(DISCOVERY_DEVICE);
    device[DISCOVERY_DEVICE_IDENTIFIERS][0] = DEVICEID;
    device[DISCOVERY_DEVICE_MANUFACTURER] = BASETOPIC;
    device[DISCOVERY_DEVICE_NAME] = DEVICENAME;
    device[DISCOVERY_DEVICE_HW_VERSION] = hardware_version_major "." hardware_version_minor "." hardware_version_patch;
    device[DISCOVERY_DEVICE_SW_VERSION] = firmware_version_major "." firmware_version_minor "." firmware_version_patch;
    size_t len = measureJson(jsonDoc) + 1;
    char* jsonStr = new char[len];
    if (jsonStr) {
      serializeJson(jsonDoc, jsonStr, len);
      espMqttManager::mqttClient.publish(BASETOPIC "/homeassistant/sensor/" DEVICEID "/uptime/config", 2, true, jsonStr);
      delete[] jsonStr;
    }
  }
  {
    // Signal strength statistic
    StaticJsonDocument<512> jsonDoc;
    jsonDoc[DISCOVERY_NAME] = DEVICENAME " signal strength";
    jsonDoc[DISCOVERY_UNIQUE_ID] = DEVICEID "signal";
    jsonDoc[DISCOVERY_BASETOPIC] = BASETOPIC "/" DEVICEID;
    jsonDoc[DISCOVERY_STATE_TOPIC] = "~/$system/signal";
    jsonDoc[DISCOVERY_OPTIMISTIC] = false;
    JsonObject availability  = jsonDoc[DISCOVERY_AVAILABILITY].createNestedObject();
    availability[DISCOVERY_TOPIC] = "~/$system/status";
    availability[DISCOVERY_PAYLOAD_AVAILABLE] = "online";
    availability[DISCOVERY_PAYLOAD_NOT_AVAILABLE] = "offline";
    jsonDoc[DISCOVERY_AVAILABILITY_MODE] = "latest";
    jsonDoc[DISCOVERY_ICON] = "mdi:wifi";
    JsonObject device  = jsonDoc.createNestedObject(DISCOVERY_DEVICE);
    device[DISCOVERY_DEVICE_IDENTIFIERS][0] = DEVICEID;
    device[DISCOVERY_DEVICE_MANUFACTURER] = BASETOPIC;
    device[DISCOVERY_DEVICE_NAME] = DEVICENAME;
    device[DISCOVERY_DEVICE_HW_VERSION] = hardware_version_major "." hardware_version_minor "." hardware_version_patch;
    device[DISCOVERY_DEVICE_SW_VERSION] = firmware_version_major "." firmware_version_minor "." firmware_version_patch;
    size_t len = measureJson(jsonDoc) + 1;
    char* jsonStr = new char[len];
    if (jsonStr) {
      serializeJson(jsonDoc, jsonStr, len);
      espMqttManager::mqttClient.publish(BASETOPIC "/homeassistant/sensor/" DEVICEID "/signal/config", 2, true, jsonStr);
      delete[] jsonStr;
    }
  }
  {
    // Free (heap) memory statistic
    StaticJsonDocument<512> jsonDoc;
    jsonDoc[DISCOVERY_NAME] = DEVICENAME " free memory";
    jsonDoc[DISCOVERY_UNIQUE_ID] = DEVICEID "memory";
    jsonDoc[DISCOVERY_BASETOPIC] = BASETOPIC "/" DEVICEID;
    jsonDoc[DISCOVERY_STATE_TOPIC] = "~/$system/memory";
    jsonDoc[DISCOVERY_OPTIMISTIC] = false;
    JsonObject availability  = jsonDoc[DISCOVERY_AVAILABILITY].createNestedObject();
    availability[DISCOVERY_TOPIC] = "~/$system/status";
    availability[DISCOVERY_PAYLOAD_AVAILABLE] = "online";
    availability[DISCOVERY_PAYLOAD_NOT_AVAILABLE] = "offline";
    jsonDoc[DISCOVERY_AVAILABILITY_MODE] = "latest";
    jsonDoc[DISCOVERY_ICON] = "mdi:memory";
    JsonObject device  = jsonDoc.createNestedObject(DISCOVERY_DEVICE);
    device[DISCOVERY_DEVICE_IDENTIFIERS][0] = DEVICEID;
    device[DISCOVERY_DEVICE_MANUFACTURER] = BASETOPIC;
    device[DISCOVERY_DEVICE_NAME] = DEVICENAME;
    device[DISCOVERY_DEVICE_HW_VERSION] = hardware_version_major "." hardware_version_minor "." hardware_version_patch;
    device[DISCOVERY_DEVICE_SW_VERSION] = firmware_version_major "." firmware_version_minor "." firmware_version_patch;
    size_t len = measureJson(jsonDoc) + 1;
    char* jsonStr = new char[len];
    if (jsonStr) {
      serializeJson(jsonDoc, jsonStr, len);
      espMqttManager::mqttClient.publish(BASETOPIC "/homeassistant/sensor/" DEVICEID "/memory/config", 2, true, jsonStr);
      delete[] jsonStr;
    }
  }
  espMqttManager::sessionReady();
}

void sendStats() {
  char payload[18] = {'\0'};  // uptime: 18446744073709551615 / 1000, signal: 100, heap: 250000
  snprintf(payload, sizeof(payload), "%" PRIu64, uptime.getUptime() / 1000);
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/uptime", 0, false, payload);
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/uptimereadable", 0, false, uptime.getUptimeStr());
  snprintf(payload, sizeof(payload), "%u", espMqttManagerHelpers::signalQuality());
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/signal", 0, false, payload);
  snprintf(payload, sizeof(payload), "%u", ESP.getFreeHeap());
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/memory", 0, false, payload);
}

void onWiFiConnected() {
  Serial.print("WiFi connected\n");
  WiFi.hostname(DEVICEID);
}

void onWiFiDisconnected() {
  Serial.print("WiFi disconnected\n");
}

void onMqttConnected() {
  Serial.print("MQTT connected\n");
  espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/status", 1, true, "online");
  lastStats = millis();
  sendStats();
}

void onMqttDisconnected(espMqttClientTypes::DisconnectReason reason) {
  Serial.printf("MQTT disconnected: %u - %s\r\n", static_cast<uint8_t>(reason), espMqttClientTypes::disconnectReasonToString(reason));
}

void onMqttMessage(const espMqttClientTypes::MessageProperties& properties, const char* topic, const uint8_t* payload, size_t len, size_t index, size_t total) {
  (void) properties;
  if (strcmp(topic, BASETOPIC "/" DEVICEID "/$system/update") == 0) {
    Serial.printf("update: %zu - %zu/%zu\n", len, index + len, total);
    espMqttManagerHelpers::handleUpdate(payload, len, index, total);
    return;
  }
}

void onReset() {
  ESP.restart();
}

void setup() {
  #if defined(ARDUINO_ARCH_ESP32)
  Serial.begin(115200);
  #elif defined(ARDUINO_ARCH_ESP8266)
  Serial.begin(74880);
  #endif
  delay(2500);

  espMqttManager::setup();
  espMqttManager::mqttClient.setClientId(DEVICEID)
                            .setWill(BASETOPIC "/" DEVICEID "/$system/status", 1, true, "offline")
                            .onMessage(onMqttMessage);
  espMqttManager::start();
}

void loop() {
  uint32_t currentMillis = millis();

  if (espMqttManager::isConnected() && currentMillis - lastStats > statsInterval) {
    lastStats = currentMillis;
    sendStats();
  }

  if (espMqttManagerHelpers::updated) {
    espMqttManager::mqttClient.publish(BASETOPIC "/" DEVICEID "/$system/status", 1, true, "reboot");
    espMqttManager::disconnect(true);
  }

  espMqttManager::loop();
}
