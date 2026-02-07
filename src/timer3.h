#include <systemc.h>
SC_MODULE(timer3)
{
    sc_in<bool> clk;
    sc_out<sc_uint<16>> outp0;
    sc_out<sc_uint<8>> outp1;

    sc_uint<8> tim_val;
    void timer3_main();

    SC_CTOR(timer3)
    {
        SC_METHOD(timer3_main);
        sensitive<< clk.neg();
    }
};