#include "timer0.h"
void timer0::start_of_simulation( void )
{
    sc_uint<8> value = 0;
    outp0.write(value);
    outp1.write(value[0]);
    outp2.write(value[0]);
}
void timer0::timer0_main(void)
{
    tim0_val += 1;
    if (tim0_val >= 256 || clr_flag_0 == 0)
    {
        tim0_val = 0;
    }
    outp0.write(tim0_val);
    outp1.write(tim0_val[1]);
    outp2.write(tim0_val[5]);
    clr_flag_0 = clr.read();
}