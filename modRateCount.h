#include <systemc.h>
SC_MODULE(modRateCount)
{
    sc_in<bool> clk;
    sc_in<sc_uint<4>> inp0;
    sc_in<sc_uint<4>> inp1;
    sc_out<bool> outp0;
    sc_out<bool> outp1;

    void modRateCount_main();

    SC_CTOR(modRateCount)
    {
        SC_CTHREAD(modRateCount_main, clk.pos());
    }
};