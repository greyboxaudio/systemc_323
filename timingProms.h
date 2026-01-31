#include <systemc.h>
SC_MODULE(timingProms)
{
    sc_in<bool> clk, rst;
    sc_in<sc_uint<8>> inp0;
    sc_out<bool> outp0, outp1, outp2, outp3, outp4, outp5, outp6, outp7, outp8, outp9;
    sc_out<bool> outp10, outp11, outp12, outp13, outp14, outp15, outp16, outp17, outp18;

    void func();

    SC_CTOR(timingProms)
    {
        SC_CTHREAD(func, clk.pos());
        reset_signal_is(rst, true);
    }
};