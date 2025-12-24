#include "timer1.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void timer1::timer1_main(void)
{
    sc_uint<8> out_val;

    // reset code
    outp.write(0);
    wait();

    while (true)
    {
        out_val += 1;
        if (out_val >= 256)
        {
            out_val = 0;
        }
        outp.write(out_val); // write output
        wait();
    }
}