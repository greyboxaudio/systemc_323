#include <systemc.h>
SC_MODULE(modRateCountProm)
{
    sc_in<sc_uint<8>> address0, address1;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1, outp2;

    void func();

    SC_CTOR(modRateCountProm)
    {
        SC_METHOD(func);
        sensitive << address0 << address1;
    }
};