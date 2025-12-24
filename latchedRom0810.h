#include <systemc.h>
SC_MODULE(rom0810)
{
    sc_in<bool> clk, rst, enable;
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1;

    void rom8_main();

    SC_CTOR(rom0810)
    {
        SC_CTHREAD(rom8_main, clk.pos());
        reset_signal_is(rst, true);
    }
};