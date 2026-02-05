#include "sg323.h"
#include "eproms.h"
// FIR Main thread
// scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void sg323::func(void)
{
    // set up variables
    sc_uint<4> grayCode[16]{15, 14, 12, 13, 9, 8, 10, 11, 3, 2, 0, 1, 5, 4, 6, 7};
    sc_uint<8> timer0, TCB2_7, MC5_12;
    sc_uint<8> data0, data1, nROW, nCOL;
    bool nTCB1, nMOD, RAS, CAS, nSYNCCLEAR, TCB7A, TCB2, cOUT, cIN;
    bool nTCB1_flag, TCB7A_flag, RAS_flag, CAS_flag;
    sc_uint<16> dlyAddress, dlyModAddress, writeAddress, dramAddress;
    sc_uint<8> dlyData0, dlyData1, writeAddrData, address0, address1, rowAddress, colAddress;
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

        outp0.write(dramAddress);
        outp1.write(address0);

        //dram address
        if (RAS == 1 && RAS_flag == 0)
        {
           rowAddress = address1;
        }
        if (CAS == 1 && CAS_flag == 0)
        {
           colAddress = address1;
           dramAddress = rowAddress + (colAddress << 8);
        }

        //address bit shift
        address1 = address0[6] + ((address0 & 0x3f)<< 1) + (address0[7] << 7);

        // row carry out latch
        if (nTCB1 == 1 && nTCB1_flag == 0)
        {
            cIN = cOUT & RAS;
        }
        // delay adder
        for  (sc_uint<8> i = 0; i < 8; i++)
        {
            address0[i] = writeAddrData[i] ^ dlyData1[i] ^ cIN;
            cIN = (writeAddrData[i] & dlyData1[i]) | (cIN & (writeAddrData[i] ^ dlyData1[i]));
        }
        cOUT = cIN;
        cIN = 0;

        // row/col mux
        if (TCB2 == 0)
        {
            writeAddrData = ~nROW;
        }
        else
        {
            writeAddrData = ~nCOL;
        }

        // write address counter
        nROW = writeAddress & 0xff;
        nCOL = writeAddress >> 8;
        if (TCB7A_flag == 0 && TCB7A == 1)
        {
            writeAddress += 1;
            if (writeAddress > 65535)
            {
                writeAddress = 0;
            }
        }

        // delay data Register
        if (nTCB1 == 1 && nTCB1_flag == 0)
        {
            dlyData1 = dlyData0;
        }

        // delay chip select
        if (nMOD)
        {
            dlyData0 = d0808_626[dlyAddress];
        }
        else
        {
            dlyData0 = d0807[dlyModAddress];
        }

        // delay eprom
        dlyAddress = TCB2_7 + ((predly & 0x07) << 6) + ((program & 0x07) << 9) + ((predly & 0x08) << 12) + ((program & 0x08) << 13);
        // delay mod eprom
        dlyModAddress = (TCB2_7 >> 1) + ((MC5_12 & 0xfe) << 5);

        // dac slot address counter
        TCB7A_flag = TCB7A;
        TCB2_7 += 1;
        TCB7A = TCB2_7[5].to_bool();
        TCB2 = TCB2_7[0].to_bool();
        if (nSYNCCLEAR == 0)
        {
            TCB2_7 = 0;
        }

        // timing prom data & latches
        nTCB1_flag = nTCB1;
        RAS_flag = RAS;
        CAS_flag = CAS;
        data0 = d0810[timer0];
        data1 = d0811[timer0];
        nTCB1 = !timer0[1].to_bool();
        nSYNCCLEAR = data0[0].to_bool();
        nMOD = data0[7].to_bool();
        RAS = data0[4].to_bool();
        CAS = data0[3].to_bool();

        // count main timer
        timer0 += 1;
        if (timer0 > 255)
        {
            timer0 = 0;
        }

        wait();
    }
}