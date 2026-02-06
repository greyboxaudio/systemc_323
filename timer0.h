#include <systemc.h>
SC_MODULE(timer0)
{
    sc_in<bool> clk;
    sc_out<sc_uint<8>> outp0;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void timer0_main();

    SC_CTOR(timer0)
    {
        SC_METHOD(timer0_main);
        sensitive<< clk.pos();
    }
};