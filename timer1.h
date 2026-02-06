#include <systemc.h>
SC_MODULE(timer1)
{
    sc_in<bool> clk, clr;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1, outp5;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void timer1_main();

    SC_CTOR(timer1)
    {
        SC_METHOD(timer1_main);
        sensitive<< clk.pos();
    }
};