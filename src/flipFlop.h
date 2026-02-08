#include <systemc.h>
SC_MODULE(flipFlop)
{
    sc_in<bool> clk, clr, inp0;
    sc_out<bool> outp0, outp1;

    void start_of_simulation( void ) override;
    void flipFlop_main();

    SC_CTOR(flipFlop)
    {
        SC_METHOD(flipFlop_main);
        sensitive << clk.pos();
        dont_initialize();
    }
};