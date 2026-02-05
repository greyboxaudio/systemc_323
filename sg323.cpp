#include "sg323.h"
#include "eproms.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void sg323::func(void)
{
    // 
    sc_uint<8> timer0;
    // reset code
    outp0.write(0);
    wait();
    // main loop
    while (true)
    {
        //count main timer 
        timer0 += 1;
        if (timer0 > 255)
        {
            timer0 = 0;
        }
        //timing proms
        sc_uint<8> address = timer0;
        sc_bv<8> data0 = sc_bv<8>(d0810[address]);
        sc_bv<8> data1 = sc_bv<8>(d0811[address]);
        sc_bit nTC1 = sc_bit(address[1]);

        






        wait();
    }
}