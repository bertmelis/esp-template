## Template for esp8266 and esp32 devices

Template for my devices using [espMqttManager](https://github.com/bertmelis/espMqttManagerClient).
Adds discovery for Home Assistant over MQTT.

## Usage

I use platformio.

- edit `data/config.json` (optionally add credentials)
- edit `main.cpp`
- build and upload:

```
$ pio run -t uploadfs
$ pio run -t upload
```

Done.

## License

This library is released under the MIT Licence. A copy is included in the repo.
