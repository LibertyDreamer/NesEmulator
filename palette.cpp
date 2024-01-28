#include "palette.h"

void Palette::choose_palette(PaletteNames name)
{
    const unsigned char *from;

    switch (name) {
    case PaletteNames::LUT_2C04_01:
        from = PaletteLUT_2C04_0001;
        break;
    case PaletteNames::LUT_2C04_02:
        from = PaletteLUT_2C04_0002;
        break;
    case PaletteNames::LUT_2C04_03:
        from = PaletteLUT_2C04_0003;
        break;
    case PaletteNames::LUT_2C04_04:
        from = PaletteLUT_2C04_0004;
        break;
    default:
        throw("Pallete not found");
        break;
    }

    for (int i = 0; i < 64; ++i) {
        chosen_palette[i] = from[i];
    }
}

Palette::Palette()
{
    choose_palette(PaletteNames::LUT_2C04_01);
}

Palette::Palette(PaletteNames name)
{
    choose_palette(name);
}
