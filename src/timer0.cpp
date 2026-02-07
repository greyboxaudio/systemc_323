#include "timer0.h"
void timer0::start_of_simulation( void )
{
    sc_uint<8> value = 0;
    outp0.write(value);
    outp1.write(value[0]);
    tim_val = 0;
}
void timer0::timer0_main(void)
{
    if (tim_val >= 256)
    {
        tim_val = 0;
    }
    outp0.write(tim_val);
    outp1.write(tim_val[1]);
    tim_val += 1;
}