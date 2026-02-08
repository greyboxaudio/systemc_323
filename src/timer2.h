#include <systemc.h>
SC_MODULE(timer2)
{
    sc_in<bool> clk, ld;
    sc_in<sc_uint<8>> inp0;
    sc_out<bool> outp0;

    sc_uint<8> tim_val;
    bool ld_flag;
    void timer2_main();

    SC_CTOR(timer2)
    {
        SC_METHOD(timer2_main);
        sensitive<< clk.pos();
        dont_initialize();
    }
};