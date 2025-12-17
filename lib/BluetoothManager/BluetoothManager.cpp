#include "BluetoothManager.h"
#include "Config.h"
#include <Arduino.h>

void BluetoothManager::begin() {
    if (!SerialBT.begin(BT_DEVICE_NAME)) {
        Serial.println("❌ Bluetooth gagal start");
        while (true);
    }

    Serial.print("✅ Bluetooth aktif dengan nama: ");
    Serial.println(BT_DEVICE_NAME);
    Serial.println("Menunggu koneksi HP...");
}

void BluetoothManager::handle() {
    handleConnection();
    handleIncomingData();
}

void BluetoothManager::handleConnection() {
    bool connected = SerialBT.hasClient();

    if (connected && !lastConnected) {
        lastConnected = true;

        Serial.println("📱 HP terhubung via Bluetooth");

        // MAC ADDRESS ESP32 (LOCAL)
        uint8_t mac[6];
        SerialBT.getBtAddress(mac);

        char macStr[18];
        sprintf(macStr,
                "%02X:%02X:%02X:%02X:%02X:%02X",
                mac[0], mac[1], mac[2],
                mac[3], mac[4], mac[5]);

        Serial.print("🔗 MAC ESP32: ");
        Serial.println(macStr);
    }

    if (!connected && lastConnected) {
        lastConnected = false;
        Serial.println("❌ HP terputus dari Bluetooth");
    }
}

void BluetoothManager::handleIncomingData() {
    if (!SerialBT.available()) return;

    String msg = "";
    while (SerialBT.available()) {
        msg += (char)SerialBT.read();
        delay(2);
    }

    Serial.print("💬 Chat dari HP: ");
    Serial.println(msg);

#if BT_ENABLE_ECHO
    SerialBT.print("ESP32 menerima: ");
    SerialBT.println(msg);
#endif
}
