#include <systemc.h>
SC_MODULE(tb)
{
    sc_in<bool> clk;
    sc_out<bool> rst;
    /*sc_out<sc_uint<8>> inp; // inp & outp are the opposite of fir
    sc_out<bool> inp_vld;
    sc_in<bool> inp_rdy;*/
    sc_in<sc_uint<8>> outp0, outp1, outp2, outp3, outp4, outp5; // inp & outp are the opposite of fir
    // separate source & sink threads
    //void source();
    void sink();

    SC_CTOR(tb)
    {
        //SC_CTHREAD(source, clk.pos());
        SC_CTHREAD(sink, clk.pos());
    }
};