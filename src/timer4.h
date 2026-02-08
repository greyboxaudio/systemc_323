#include <systemc.h>
SC_MODULE(timer4)
{
    sc_in<bool> clk;
    sc_out<sc_uint<8>> outp0, outp1;

    sc_uint<16> tim_val;

    void timer4_main();

    SC_CTOR(timer4)
    {
        SC_METHOD(timer4_main);
        sensitive << clk.neg();
        dont_initialize();
    }
};