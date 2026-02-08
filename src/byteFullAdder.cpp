#include "byteFullAdder.h"

void byteFullAdder::func(void)
{
    sc_uint<8> inputA;
    sc_uint<8> inputB;
    sc_uint<8> sum;
    bool carry;

    inputA = inp0.read();
    inputB = inp1.read();
    carry = c0.read();

    for (int i = 0; i < 8; i++)
    {
        sum[i] = inputA[i] ^ inputB[i] ^ carry;
        carry = (inputA[i] & inputB[i]) | (carry & (inputA[i] ^ inputB[i]));
    }

    outp0.write(sum);
    c4.write(carry);
}