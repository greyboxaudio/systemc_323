#include "timingProms.h"
#include "eproms.h"

void timingProms::func(void)
{
        sc_uint<8> address = inp0.read();
        sc_uint<8> data0 = d0810[address];
        sc_uint<8> data1 = d0811[address];
        outp0.write(data0[0]);
        outp1.write(data0[1]);
        outp2.write(data0[2]);
        outp3.write(data0[3]);
        outp4.write(data0[4]);
        outp5.write(data0[5]);
        outp6.write(data0[6]);
        outp7.write(data0[7]);
        outp8.write(data1[0]);
        outp9.write(data1[1]);
        outp10.write(data1[2]);
        outp11.write(data1[3]);
        outp12.write(data1[4]);
        outp13.write(data1[5]);
        outp14.write(data1[6]);
        outp15.write(data1[7]);
}