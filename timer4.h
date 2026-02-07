#include <systemc.h>
SC_MODULE(timer4)
{
    sc_in<bool> clk;
    sc_out<sc_uint<8>> outp0, outp1;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void timer4_main();

    SC_CTOR(timer4)
    {
        SC_METHOD(timer4_main);
        sensitive<< clk.neg();
    }
};