#include "nand.h"
    void nand::nand_main(void)
    {
        bool a = inp0.read();
        bool b = inp1.read();
        bool y = ~(a & b);
        outp0.write(y);
    }