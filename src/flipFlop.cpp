#include "flipFlop.h"
void flipFlop::start_of_simulation( void ){
    bool value = 0;
    outp0.write(value);
    outp1.write(~value);
}
void flipFlop::flipFlop_main(void)
{
    if (clr.read() == 1)
    {
        bool q = inp0.read();
        outp0.write(q);
        outp1.write(~q);
    }
}