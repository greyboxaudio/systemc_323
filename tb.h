#include <systemc.h>
SC_MODULE(tb)
{
    sc_in<bool> clk;
    sc_out<bool> rst;
    sc_out<sc_int<16>> inp; //inp & outp are the opposite of fir
    sc_out<bool> inp_vld;
    sc_in<bool> inp_rdy;
    sc_in<sc_int<16>> outp; //inp & outp are the opposite of fir
    sc_in<bool> outp_vld;
    sc_out<bool> outp_rdy;

    //separate source & sink threads
    void source();
    void sink();

    SC_CTOR(tb){
        SC_CTHREAD(source, clk.pos());
        SC_CTHREAD(sink, clk.pos());
    }
};