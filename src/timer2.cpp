#include "timer2.h"

void timer2::timer2_main(void)
{
    tim_val += 1;
    bool carry = tim_val[4];
    if (ld_flag == 0)
    {
        tim_val = inp0.read();
    }
    outp0.write(carry);
    ld_flag = ld.read();
}