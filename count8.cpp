#include "count8.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void count8::count8_main(void)
{
    sc_uint<8> out_val;

    // reset code
    outp_vld.write(0);
    outp.write(0);
    wait();

    while (true)
    {
        // handshake
        outp_vld.write(1);
        outp.write(out_val); // write output
        do
        {
            wait();
        } while (!outp_rdy.read());
        outp_vld.write(0);

        out_val += 1;
        if (out_val >= 256)
        {
            out_val = 0;
        }
    }
}