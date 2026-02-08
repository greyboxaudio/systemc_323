#include "timer4.h"
void timer4::timer4_main(void)
{
    tim_val += 1;
    if (tim_val >= 65536)
    {
        tim_val = 0;
    }
    outp0.write(tim_val & 0xff);
    outp1.write(tim_val >> 8);
}