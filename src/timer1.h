#include <systemc.h>
SC_MODULE(timer1)
{
    sc_in<bool> clk, clr;
    sc_out<sc_uint<8>> outp0, outp1;
    sc_out<bool> outp2, outp3;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    sc_uint<8> tim1_val;
    bool clr_flag_1;
    void timer1_main();

    SC_CTOR(timer1)
    {
        SC_METHOD(timer1_main);
        sensitive<< clk.pos();
    }
};