#include <systemc.h>
SC_MODULE(tb323)
{
    sc_in<bool> clk;
    sc_out<bool> rst;
    /*sc_out<sc_uint<8>> inp; // inp & outp are the opposite of fir
    sc_out<bool> inp_vld;
    sc_in<bool> inp_rdy;*/
    sc_in<sc_uint<8>> outp1; // inp & outp are the opposite of fir
    sc_in<sc_uint<16>> outp0;
    // separate source & sink threads
    //void source();
    void sink();

    SC_CTOR(tb323)
    {
        //SC_CTHREAD(source, clk.pos());
        SC_CTHREAD(sink, clk.pos());
    }
};