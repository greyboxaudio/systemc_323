#include <systemc.h>
SC_MODULE(timingProms)
{
    sc_in<bool> clk, rst;
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<8>> outp0;
    sc_out<sc_uint<8>> outp1;
    sc_out<bool> outp2;

    void rom0810();
    void rom0811();
    void tc1();

    SC_CTOR(timingProms)
    {
        SC_CTHREAD(rom0810, clk.pos());
        reset_signal_is(rst, true);
        SC_CTHREAD(rom0811, clk.pos());
        reset_signal_is(rst, true);
        SC_CTHREAD(tc1, clk.pos());
        reset_signal_is(rst, true);
    }
};