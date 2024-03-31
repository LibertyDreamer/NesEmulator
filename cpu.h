#ifndef NESEMULATOR_CPU_H
#define NESEMULATOR_CPU_H

#include "memory_mapped.h"

class CPU {
public:
    CPU(MemoryMapped *mm) : mm_(mm) {
        power_up();
    }

    void execute();

    void power_up(){
        alu_ = 0;
        x_ = 0;
        y_ = 0;

        status_register_.carry = 0;
        status_register_.zero = 0;
        status_register_.decimal = 0;
        status_register_.overflow = 0;
        status_register_.negative = 0;
        status_register_.interrupt_disable = 1;

        stack_pointer_ = 0xFD;
        mm_->write(0x4017, 0);
        mm_->write(0x4015, 0);

        for(uint16_t i = 0x4000; i <= 0x4013; ++i){
            mm_->write(i, 0);
        }
    }

    void reset(){
        stack_pointer_ -= 3;
        status_register_.interrupt_disable = 1;

    }

private:

    void AND() {


    }

    MemoryMapped * mm_;

    uint8_t alu_;
    uint8_t x_;
    uint8_t y_;
    uint16_t program_counter_;
    uint8_t stack_pointer_;

    struct StatusRegistr {
        uint8_t carry : 1;
        uint8_t zero : 1;
        uint8_t interrupt_disable : 1;
        uint8_t decimal : 1;
        uint8_t b_flag : 1;
        const uint8_t no_use : 1 = 1;
        uint8_t overflow : 1;
        uint8_t negative : 1;
    } status_register_;
};

#endif //NESEMULATOR_CPU_H
