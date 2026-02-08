#include "flipFlop.h"
void flipFlop::flipFlop_clear(void)
{
    bool clear = clr.read();
    if (!clear)
    { 
        bool q = 0;
        outp0.write(q);
        outp1.write(!q);
    }
}
void flipFlop::flipFlop_main(void)
{
    bool clear = clr.read();
    bool q = inp0.read();
    if (clear)
    {
        outp0.write(q);
        outp1.write(!q);
    }
}