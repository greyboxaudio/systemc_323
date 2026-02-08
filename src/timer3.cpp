#include "timer3.h"

void timer3::timer3_main(void)
{
    tim_val += 1;
    if (tim_val >= 8192)
    {
        tim_val = 0;
    }
    outp0.write(tim_val & 0x1ff);
    outp1.write(tim_val >> 6);
}