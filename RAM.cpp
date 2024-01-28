#include <iostream>



class Memory: public IDevice
{
    uint8_t mem[0x800];
    public:
    void show_mem()
    {
        std::cout << "Show Memory" << std::endl;
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
        return "Memory";
    }

};



class CPU
{

};


class PPU: public IDevice
{
    struct ControlRegister
    {
        uint8_t base_nametable_address:2;
        uint8_t VRAM:1;
        uint8_t sprite_pattern:1;
        uint8_t background_pattern:1;
        //todo
    };

    union
    {
        ControlRegister bitfield;
        uint8_t value;
    }control_register;

    uint8_t* ptr_to_reg[20];

    public:

    PPU()
    {
        ptr_to_reg[0] = &control_register.value;
    }

    uint8_t read(uint16_t address)
    {
        return 0;
    }

    void write(uint16_t address, uint8_t value)
    {
        *ptr_to_reg[address] = value;
    }

    std::string show_name()
    {
        return "PPU";
    }
};

int main() {
    CPU cpu;
    PPU* ppu = new PPU();
    RAM ram;
    Memory* mem = new Memory();


    //$0000–$07FF	$0800	2 KB internal RAM
    ram.connect(mem, {0,0x7FF}, 0);
    //mirroring
    //$0800–$0FFF	$0800	Mirrors of $0000–$07FF
    //$1000–$17FF	$0800
    //$1800–$1FFF	$0800
    ram.connect(mem, {0x800,0x0FFF},   -0x800);
    ram.connect(mem, {0x1000,0x17FF}, -0x1000);
    ram.connect(mem, {0x1800,0x1FFF}, -0x1800);

    //$2000–$2007	$0008	NES PPU registers
    //$2008–$3FFF	$1FF8	Mirrors of $2000–$2007 (repeats every 8 bytes)
    for(uint16_t i = 0x2000; i < 0x4FFF; i+=8)
    {
        ram.connect(ppu, {i, i+7}, -i);
    }

    for(int i = 0x800; i < 0x1000; ++i)
    {
        ram.write(i, i);
    }

    mem->show_mem();

    delete mem;
    delete ppu;
    return 0;
}
