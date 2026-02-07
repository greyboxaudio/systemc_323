#include "timer1.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
sc_uint<8> tim1_val;
bool clr_flag_1;
void timer1::timer1_main(void)
{
    tim1_val += 1;
    if (tim1_val >= 256 || clr_flag_1 == 0)
    {
        tim1_val = 0;
    }
    outp0.write(tim1_val);
    outp1.write(tim1_val >> 1);
    outp2.write(tim1_val[0]);
    outp3.write(tim1_val[5]);
    clr_flag_1 = clr.read();
}