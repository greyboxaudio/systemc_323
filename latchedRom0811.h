#include <systemc.h>
SC_MODULE(rom0811)
{
    sc_in<bool> clk, rst, enable;
    sc_in<sc_uint<8>> inp;
    sc_out<sc_uint<8>> outp;

    void rom8_main();

    SC_CTOR(rom0811)
    {
        SC_CTHREAD(rom8_main, clk.pos());
        reset_signal_is(rst, true);
    }
};