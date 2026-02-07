#include "timer1.h"
void timer1::start_of_simulation( void )
{
    sc_uint<8> value = 0;
    outp0.write(value);
    outp1.write(value);
    outp2.write(value[0]);
    outp3.write(value[0]);
}
void timer1::timer1_main(void)
{
    tim1_val += 1;
    if (tim1_val >= 256 || clr_flag_1 == 0)
    {
        tim1_val = 0;
    }
    outp0.write(tim1_val);
    outp1.write(tim1_val >> 1);
    outp2.write(tim1_val[0]);
    outp3.write(tim1_val[5]);
    clr_flag_1 = clr.read();
}