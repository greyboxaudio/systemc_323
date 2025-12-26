#include <systemc.h>
SC_MODULE(latchedMux)
{
    sc_in<bool> clk, sel;
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<8>> inp1;
    sc_out<sc_uint<8>> outp0;

    void func()
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

    SC_CTOR(latchedMux)
    {
        SC_METHOD(func);
        sensitive << clk.neg();
    }
};