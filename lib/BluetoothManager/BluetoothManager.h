#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <BluetoothSerial.h>

class BluetoothManager {
public:
    void begin();
    void handle();

private:
    BluetoothSerial SerialBT;
    bool lastConnected = false;

    void handleConnection();
    void handleIncomingData();
};

#endif
