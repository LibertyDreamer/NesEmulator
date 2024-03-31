#ifndef I_DEVICE_H
#define I_DEVICE_H

#include <inttypes.h>

class IDevice
{
public:
    virtual uint8_t read(uint16_t address)=0;
    virtual void write(uint16_t address, uint8_t value)=0;
};

#endif // I_DEVICE_H
