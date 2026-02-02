#include "timer0.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void timer0::timer0_main(void)
{
    sc_uint<8> out_val;

    // reset code
    outp0.write(0);
    wait();

    while (true)
    {
        if (out_val > 255)
        {
            out_val = 0;
        }
        outp0.write(out_val); 
        out_val += 1;
        // write output
        wait();
    }
}