#include "timer2.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments

void timer2::timer2_main(void)
{
    tim2_val += 1;
    bool carry = tim2_val[4];
    if (ld_flag_2 == 0)
    {
        tim2_val = inp0.read();
    }
    outp0.write(carry);
    ld_flag_2 = ld.read();
}