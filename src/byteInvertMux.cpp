#include "byteInvertMux.h"

    void byteInvertMux::func(void)
    {
        sc_uint<8> data_a = inp0.read();
        sc_uint<8> data_b = inp1.read();
        bool select = sel.read();

        if (select)
        {
            outp0.write(~data_b);
        }
        else
        {
            outp0.write(~data_a);
        }
    }