#include "timer1.h"
void timer1::tim1_clr(void)
{
    clr_flag = clr.read();
}
void timer1::timer1_main(void)
{
    tim_val += 1;
    if (tim_val >= 256 || clr_flag == 0)
    {
        tim_val = 0;
    }
    outp0.write(tim_val);
    outp1.write(tim_val >> 1);
    outp2.write(tim_val[0]);
    outp3.write(tim_val[5]);
}