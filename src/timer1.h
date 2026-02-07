#include <systemc.h>
SC_MODULE(timer1)
{
    sc_in<bool> clk, clr;
    sc_out<sc_uint<8>> outp0, outp1;
    sc_out<bool> outp2, outp3;

    sc_uint<8> tim_val;
    bool clr_flag;

    void start_of_simulation( void ) override;
    void timer1_main();
    void tim1_clr();

    SC_CTOR(timer1)
    {
        SC_METHOD(timer1_main);
        sensitive<< clk.pos();
        SC_METHOD(tim1_clr);
        sensitive<< clr;
    }
};