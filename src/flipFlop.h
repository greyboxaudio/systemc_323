#include <systemc.h>
SC_MODULE(flipFlop)
{
    sc_in<bool> clk, clr, inp0;
    sc_out<bool> outp0, outp1;

    void flipFlop_main();
    void flipFlop_clear();

    SC_CTOR(flipFlop)
    {
        SC_METHOD(flipFlop_main);
        sensitive << clk.pos();
        dont_initialize();
        SC_METHOD(flipFlop_clear);
        sensitive << clr;
        dont_initialize();
    }
};