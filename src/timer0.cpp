#include "timer0.h"
void timer0::timer0_main(void)
{
    tim_val += 1;
    if (tim_val >= 256)
    {
        tim_val = 0;
    }
    outp0.write(tim_val);
    outp1.write(tim_val[1]);
}