#include <iostream>
#include "memory_mapped.h"
#include "cpu.h"
#include "ram.h"

using namespace std;

int main()
{
    RAM memory;
    MemoryMapped mm;
    mm.connect(&memory, {0,0x07FF}, 0);
    mm.connect(&memory, {0x0800, 0x0FFF}, -0x0800);
    mm.connect(&memory, {0x1000, 0x17FF}, -0x1000);
    mm.connect(&memory, {0x1800, 0x1FFF}, -0x1800);
    //CPU cpu(&mm);

    mm.write(10, 255);
    //mm.write(0x07FF, 10);
    //mm.write(0x1000, 11);
    mm.write(0x1800, 12);
    return 0;
}
