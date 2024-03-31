#ifndef RAM_H
#define RAM_H
#include <inttypes.h>
#include "i_device.h"

class RAM : public IDevice {
public:

private:
    uint8_t memory_[0x0800] = {};

public:

    uint8_t read(uint16_t address){
        return memory_[address];
    }
    void write(uint16_t address, uint8_t value){
        memory_[address] = value;
    }
};

#endif // RAM_H
