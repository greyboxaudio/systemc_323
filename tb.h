#include <systemc.h>
SC_MODULE(tb)
{
    sc_in<bool> clk;
    sc_out<bool> rst;
    /*sc_out<sc_uint<8>> inp; // inp & outp are the opposite of fir
    sc_out<bool> inp_vld;
    sc_in<bool> inp_rdy;*/
    sc_in<sc_uint<8>> outp0; // inp & outp are the opposite of fir
    sc_in<sc_uint<8>> outp1;
    sc_in<sc_uint<8>> outp2;
    sc_in<sc_uint<1>> outp3;
    // separate source & sink threads
    //void source();
    void sink();

    SC_CTOR(tb)
    {
        //SC_CTHREAD(source, clk.pos());
        SC_CTHREAD(sink, clk.pos());
    }
};