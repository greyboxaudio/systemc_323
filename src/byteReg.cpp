#include "byteReg.h"
void byteReg::start_of_simulation(void)
{
    data = 0;
    outp0.write(data);
}
void byteReg::read(void)
{
    data = inp0.read();
}
void byteReg::latch(void)
{
    outp0.write(data);
}