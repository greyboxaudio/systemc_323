#include <systemc.h>
SC_MODULE(timer0)
{
    sc_in<bool> clk;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1;

    sc_uint<8> tim_val;

    void timer0_main();

    SC_CTOR(timer0)
    {
        SC_METHOD(timer0_main);
        sensitive << clk.pos();
        dont_initialize();
    }
};