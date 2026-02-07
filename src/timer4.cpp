#include "timer4.h"
void timer4::start_of_simulation( void )
{
    sc_uint<8> value = 0;
    outp0.write(value);
    outp1.write(value);
    tim_val = 0;
}
void timer4::timer4_main(void)
{
    if (tim_val >= 65536)
    {
        tim_val = 0;
    }
    outp0.write(tim_val & 0xff);
    outp1.write(tim_val >> 8);
    tim_val += 1;
}