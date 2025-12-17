#include "BluetoothManager.h"
#include "Config.h"
#include <Arduino.h>

void BluetoothManager::begin() {
    if (!SerialBT.begin(BT_DEVICE_NAME)) {
        Serial.println("Bluetooth gagal start");
        while (true);
    }
    Serial.println("Bluetooth aktif, menunggu koneksi HP...");
}

void BluetoothManager::handle() {
    if (SerialBT.hasClient()) {
        if (!lastState) {
            Serial.println("HP terhubung via Bluetooth");
            lastState = true;
        }
    } else {
        if (lastState) {
            Serial.println("HP terputus");
            lastState = false;
        }
    }

    if (SerialBT.available()) {
        String msg = "";
        while (SerialBT.available()) {
            msg += (char)SerialBT.read();
            delay(2);
        }
        Serial.print("Pesan dari HP: ");
        Serial.println(msg);

        SerialBT.print("ESP32 menerima: ");
        SerialBT.println(msg);
    }
}