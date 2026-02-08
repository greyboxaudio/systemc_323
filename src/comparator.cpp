#include "comparator.h"

    void comparator::comparator_main(void)
    {
        sc_uint<8> inputA = inp0.read();
        sc_uint<8> inputB = inp1.read() << 1;
        if (inputA < inputB)
        {
            outp0.write(1);
        }else{
            outp0.write(0);
        }
    }
