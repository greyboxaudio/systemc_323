#include <systemc.h>
SC_MODULE(timer0)
{
    sc_in<bool> clk, clr;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1, outp5;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    sc_uint<8> tim0_val;
    bool clr_flag_0;
    void timer0_main();

    SC_CTOR(timer0)
    {
        SC_METHOD(timer0_main);
        sensitive << clk.pos();
    }
};