#include "latchedMux.h"
void latchedMux::latchedMux_read(void)
{
    sc_uint<8> inputA = inp0.read();
    sc_uint<8> inputB = (inp1.read() & 0x7f) << 1;
    bool byteSelect = sel.read();

    if (byteSelect)
    {
        data = inputB;
    }
    else
    {
        data = inputA;
    }
}
void latchedMux::latchedMux_latch(void)
{

    outp0.write(data);
}