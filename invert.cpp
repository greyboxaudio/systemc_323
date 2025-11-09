#include "invert.h"

void invert::invert_main(void)
{
        sc_uint<8> in_val;
        sc_uint<3> bitSelect_val;
        sc_uint<1> out_val;

        in_val = inp.read(); // read input
        out_val = ~in_val[bitSelect_val]; //extract single bit and invert
        outp.write(out_val); // write output
}