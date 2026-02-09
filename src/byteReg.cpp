#include "byteReg.h"

void byteReg::byteReg_read(void)
{
    data = inp0.read();
}
void byteReg::byteReg_latch(void)
{
    outp0.write(data);
}