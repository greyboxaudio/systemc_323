#include "sg323.h"
#include "eproms.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void sg323::func(void)
{
    //set up variables
    sc_uint<4> grayCode[16]{15, 14, 12, 13, 9, 8, 10, 11, 3, 2, 0, 1, 5, 4, 6, 7};
    sc_uint<8> timer0, TCB2_7, MC5_12;
    sc_uint<8> data0, data1;
    bool nTCB1, nMOD, RAS, CAS, nSYNCCLEAR;
    sc_uint<16> dlyAddress, dlyModAddress;
    sc_uint<8> dlyData, dlyModData;
    // reset code
    outp0.write(0);
    outp1.write(0);
    wait();
    // main loop
    while (true)
    {
            // read program
    sc_uint<4> num = grayCode[inp0.read() - 1];
    num[2] = num[2] ^ num[3];
    sc_uint<4> program = num;
    // read preDelay
    num = grayCode[inp1.read() - 1];
    sc_uint<4> predly = num;
    // read program
    num = grayCode[inp2.read() - 1];
    num[2] = num[2] ^ num[3];
    sc_uint<4> decay = num;
        //delay chip select
        if (nMOD)
        {
            outp1.write(dlyData);
        }else{
            outp1.write(69);
        }
        //delay eprom
        dlyData = d0808_626[dlyAddress];
        dlyAddress = TCB2_7 + ((predly & 0x07) << 6) + ((program & 0x07) << 9) + ((predly & 0x08) << 12) + ((program & 0x08) << 13);
        //delay mod eprom
        dlyModData = d0807[dlyModAddress];
        dlyModAddress = (TCB2_7 >> 1) + ((MC5_12 & 0xfe) << 5);

        // dac slot address counter
        TCB2_7 += 1;
        if (nSYNCCLEAR == 0)
        {
            TCB2_7 = 0;
        }

        // timing prom data & latches
        data0 = d0810[timer0];
        data1 = d0811[timer0];
        nTCB1 = !timer0[1].to_bool();
        nSYNCCLEAR = data0[0].to_bool();
        nMOD = data0[7].to_bool();

        // count main timer
        timer0 += 1;
        if (timer0 > 255)
        {
            timer0 = 0;
        }

        wait();
    }
}