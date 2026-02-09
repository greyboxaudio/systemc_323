#include <systemc.h>
SC_MODULE(flipFlop)
{
    sc_in<bool> clk, clr, inp0;
    sc_out<bool> outp0, outp1;

    bool q;

    void flipFlop_main();
    void flipFlop_clear();
    void flipFlop_read();

    SC_CTOR(flipFlop)
    {
        SC_METHOD(flipFlop_main);
        sensitive << clk.pos();
        SC_METHOD(flipFlop_clear);
        sensitive << clr;
        SC_METHOD(flipFlop_read);
        sensitive << inp0;
    }
};