#include "latchedMux.h"

    void latchedMux::latchedMux_prc(void)
    {
        sc_uint<8> byte1 = inp0.read();
        sc_uint<8> byte2 = inp1.read() << 1;
        bool byteSelect = sel.read();
        if (byteSelect)
        {
            outp0.write(byte1);
        }else{
            outp0.write(byte2);
        }
    }