#include <systemc.h>
SC_MODULE(latchTC1)
{
    sc_in<bool> clk, rst, enable;
    sc_in<sc_uint<8>> inp;
    sc_out<sc_uint<1>> outp;

    void latchTC1_main();

    SC_CTOR(latchTC1)
    {
        SC_CTHREAD(latchTC1_main, clk.pos());
        reset_signal_is(rst, true);
    }
};