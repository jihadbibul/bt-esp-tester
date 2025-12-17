#include <Arduino.h>
#include "Config.h"
#include "BluetoothManager.h"

BluetoothManager bt;

void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    delay(1000);
    Serial.println("=== ESP32 Bluetooth Modular Test ===");
    bt.begin();
}

void loop() {
    bt.handle();
}