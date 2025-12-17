#include <Arduino.h>
#include "Config.h"
#include "BluetoothManager.h"

BluetoothManager bluetooth;

void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    delay(1000);
    Serial.println("=== ESP32 Bluetooth Modular ===");
    bluetooth.begin();
}

void loop() {
    bluetooth.handle();
}
