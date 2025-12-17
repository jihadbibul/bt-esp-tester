#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <BluetoothSerial.h>

class BluetoothManager {
public:
    void begin();
    void handle();

private:
    BluetoothSerial SerialBT;
    bool lastState = false;
};

#endif