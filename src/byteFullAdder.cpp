#include "byteFullAdder.h"

    void byteFullAdder::func(void){
        sc_uint<8> inputA;
        sc_uint<8> inputB;
        sc_uint<8> output;
        bool carry;

        inputA = inp0.read();
        inputB = inp1.read();
        carry = c0.read();

        for  (sc_uint<8> i = 0; i < 8; i++)
        {
            output[i] = inputA[i] ^ inputB[i] ^ carry;
            carry = (inputA[i] & inputB[i]) | (carry & (inputA[i] ^ inputB[i]));
        }
        
        outp0.write(output);
        c4.write(carry); 
    }