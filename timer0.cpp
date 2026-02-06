#include "timer0.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
sc_uint<8> tim0_val;
void timer0::timer0_main(void)
{
    outp0.write(tim0_val);
    tim0_val += 1;
    if (tim0_val > 255)
    {
        tim0_val = 0;
    }
}