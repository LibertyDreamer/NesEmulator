#include <iostream>

class IDevice
{
    public:
    virtual uint8_t read(uint16_t address)=0;
    virtual void write(uint16_t address, uint8_t value)=0;
    
    virtual std::string show_name() = 0;
};

class RealVirtualDevice1: public IDevice
{
    public:
    uint8_t mem[20];
    void show_mem()
    {
        std::cout << "Show Device 1 mem" << std::endl;
        for(auto a: mem)
        {
            std::cout << (int)a << " ";
        }
        std::cout << std::endl;
    }
    
    uint8_t read(uint16_t address)
    {
        return mem[address];
    }
    void write(uint16_t address, uint8_t value)
    {
        mem[address] = value;
    }
    
    std::string show_name()
    {
        return "RealVirtualDevice1";
    }
    
};

class RealVirtualDevice2: public IDevice
{
    public:
    uint8_t mem[20];
    void show_mem()
    {
        std::cout << "Show Device 2 mem" << std::endl;
        for(auto a: mem)
        {
            std::cout << (int)a << " ";
        }
        std::cout << std::endl;
    }
    
    uint8_t read(uint16_t address)
    {
        return mem[address];
    }
    void write(uint16_t address, uint8_t value)
    {
        mem[address] = value;
    }
    
    std::string show_name()
    {
        return "RealVirtualDevice2";
    }
};

struct LightU16Pair
{
    uint16_t from;
    uint16_t to;
};

class RAM
{
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
        std::cout << "Try to write to " << destination.device->show_name() << std::endl;
        std::cout << "Address: " << destination.address <<" Value: " << (int)value << std::endl;
        destination.device->write(destination.address, value);
    }
};


int main() {
    RAM ram;
    
    RealVirtualDevice1 rvd1;
    RealVirtualDevice2 rvd2;
    
    ram.connect(&rvd1, {0,19}, 0);
    ram.connect(&rvd2, {20,39}, -20);
    
    ram.write(20, 9);
    ram.write(8, 1);
    ram.write(19, 8);
    ram.write(25, 254);
    
    rvd1.show_mem();
    rvd2.show_mem();

    return 0;
}
