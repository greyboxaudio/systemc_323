#include "flipFlop.h"

void flipFlop::flipFlop_main(void)
{
    if (clr.read() == 1)
    {
        bool q = inp0.read();
        outp0.write(q);
        outp1.write(!q);
    }
}