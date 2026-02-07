#include "timer0.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
sc_uint<8> tim0_val;
bool clr_flag_0;
void timer0::timer0_main(void)
{
    tim0_val += 1;
    if (tim0_val >= 256 || clr_flag_0 == 0)
    {
        tim0_val = 0;
    }
    outp0.write(tim0_val);
    outp1.write(tim0_val[1]);
    outp5.write(tim0_val[5]);
    clr_flag_0 = clr.read();
}