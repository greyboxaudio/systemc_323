#include "latchTC1.h"

void latch1::latch1_main(void)
{
        sc_uint<8> in_val;
        sc_uint<1> out_val;
        outp.write(1);
        wait();

        while (true)
        {
                if (enable == true)
                {
                        outp.write(out_val);
                }
                sc_uint<8> tmp;
                tmp = ~inp.read();
                out_val = tmp[1];
                wait();
        }
}