#include "timer3.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments

void timer3::timer3_main(void)
{
    tim3_val += 1;
    if (tim3_val >= 8192)
    {
        tim3_val = 0;
    }
    outp0.write(tim3_val & 0x1ff);
    outp1.write(tim3_val >> 6);
}