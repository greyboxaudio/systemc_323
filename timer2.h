#include <systemc.h>
SC_MODULE(timer2)
{
    sc_in<bool> clk, ld;
    sc_in<sc_uint<8>> inp0;
    sc_out<bool> outp0;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void timer2_main();

    SC_CTOR(timer2)
    {
        SC_METHOD(timer2_main);
        sensitive<< clk.pos();
    }
};