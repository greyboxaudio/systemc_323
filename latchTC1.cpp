#include "latchTC1.h"

void latchTC1::latchTC1_main(void)
{
        sc_uint<8> in_val;
        sc_uint<1> out_val;
        outp0.write(1);
        wait();

        while (true)
        {
                if (enable == true)
                {
                        outp0.write(out_val);
                }
                sc_uint<8> tmp;
                tmp = ~inp0.read();
                out_val = tmp[1];
                wait();
        }
}