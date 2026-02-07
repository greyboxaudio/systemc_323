#include "latchedMux.h"

    void latchedMux::func(void)
    {
        sc_uint<8> inputA = inp0.read();
        sc_uint<8> inputB = inp1.read() << 1;
        if (sel.read() == 0)
        {
            outp0.write(inputA);
        }else{
            outp0.write(inputB);
        }
    }