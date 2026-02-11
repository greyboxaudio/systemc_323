#include "comparator.h"

    void comparator::comparator_main(void)
    {
        sc_uint<8> inputA = inp0.read();
        sc_uint<8> inputB = (inp1.read() & 0x7f) << 1;
        bool comp;
        if (inputA < inputB)
        {   
            comp = 1;
        }else{
            comp = 0;
        }
        outp0.write(comp);
    }
