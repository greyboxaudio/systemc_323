#include <systemc.h>
SC_MODULE(byteFullAdder)
{
    sc_in<bool> cIn;
    sc_in<sc_uint<8>> inp0, inp1;
    sc_out<bool> cOut;
    sc_out<sc_uint<8>> outp0;

    void func(){
        sc_uint<8> inputA;
        sc_uint<8> inputB;
        sc_uint<8> output;
        bool carry;

        inputA = inp0.read();
        inputB = inp1.read();
        carry = cIn.read();

        for  (sc_uint<8> i = 0; i < 8; i++)
        {
            output[i] = inputA[i] ^ inputB[i] ^ carry;
            carry = (inputA[i] & inputB[i]) | (carry & (inputA[i] ^ inputB[i]));
        }
        
        outp0.write(output);
        cOut.write(carry); 
    }

    SC_CTOR(byteFullAdder)
    {
        SC_METHOD(func);
        sensitive << inp0 << inp1 << cIn;
    }
};