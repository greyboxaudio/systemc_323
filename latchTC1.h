#include <systemc.h>
SC_MODULE(latch1)
{
    sc_in<bool> clk, rst, enable;
    sc_in<sc_uint<8>> inp;
    sc_out<sc_uint<1>> outp;

    void latch1_main();

    SC_CTOR(latch1)
    {
        SC_CTHREAD(latch1_main, clk.pos());
        reset_signal_is(rst, true);
    }
};