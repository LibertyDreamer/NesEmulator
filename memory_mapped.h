#ifndef MEMORY_MAPPED_H
#define MEMORY_MAPPED_H
#include <cinttypes>
#include "i_device.h"

class MemoryMapped
{
    struct LightU16Pair
    {
        uint16_t from;
        uint16_t to;
    };

    struct
    {
        IDevice* device;
        uint16_t address;
    } map[0xFFFF+1] = {};
    public:

    void connect(IDevice* device, uint16_t from, uint16_t to)
    {
        map[from] = {device, to};
    }

    void connect(IDevice* device, LightU16Pair from, uint16_t offset)
    {
        for(uint16_t i = from.from; i <= from.to; ++i)
        {
            connect(device, i, i+offset);
        }
    }

    uint8_t read(uint16_t address)
    {
        auto& destination = map[address];
        return destination.device->read(destination.address);
    }

    void write(uint16_t address, uint8_t value)
    {
        auto& destination = map[address];
        //std::cout << "Try to write to " << destination.device->show_name() << std::endl;
        //std::cout << "Address: " << destination.address <<" Value: " << (int)value << std::endl;
        destination.device->write(destination.address, value);
    }
};

#endif // MEMORY_MAPPED_H
