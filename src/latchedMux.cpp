#include "latchedMux.h"

    void latchedMux::latchedMux_prc(void)
    {
        sc_uint<8> inputA = inp0.read();
        sc_uint<8> inputB = inp1.read() << 1;
        bool byteSelect = sel.read();
        if (byteSelect)
        {
            outp0.write(inputB);
        }else{
            outp0.write(inputA);
        }
    }