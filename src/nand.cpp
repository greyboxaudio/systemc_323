#include "nand.h"
    void bitNAND::bitNAND_main(void)
    {
        outp0.write(!(inp0.read() & inp1.read()));
    }