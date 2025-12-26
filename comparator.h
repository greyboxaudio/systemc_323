#include <systemc.h>
SC_MODULE(comparator)
{
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<8>> inp1;
    sc_out<bool> outp0;

    void func()
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

    SC_CTOR(comparator)
    {
        SC_METHOD(func);
        sensitive << inp0 << inp1;
    }
};