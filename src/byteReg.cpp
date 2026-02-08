#include "byteReg.h"

void byteReg::read(void)
{
    data = inp0.read();
}
void byteReg::latch(void)
{
    outp0.write(data);
}