#include <systemc.h>
SC_MODULE(tb)
{
    sc_in<bool> clk, rst;
    sc_out<sc_int<16>> inp; //inp & outp are the opposite of fir
    sc_in<sc_int<16>> outp;

    //separate source & sink threads
    void source();
    void sink();

    SC_CTOR(tb){
        SC_CTHREAD(source, clk.pos());
        SC_CTHREAD(sink, clk.pos());
    }
};