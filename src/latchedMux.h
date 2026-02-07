#include <systemc.h>
SC_MODULE(latchedMux)
{
    sc_in<bool> clk, sel;
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<8>> inp1;
    sc_out<sc_uint<8>> outp0;

    void func();

    SC_CTOR(latchedMux)
    {
        SC_METHOD(func);
        sensitive << clk.neg();
    }
};