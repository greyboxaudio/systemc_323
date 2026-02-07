#include "timer4.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments

void timer4::timer4_main(void)
{
    tim4_val += 1;
    if (tim4_val >= 65536)
    {
        tim4_val = 0;
    }
    outp0.write(tim4_val & 0xff);
    outp1.write(tim4_val >> 8);
}