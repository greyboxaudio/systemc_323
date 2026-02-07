#include <systemc.h>
SC_MODULE(tb)
{
    sc_in<bool> clk;
    sc_out<bool> rst;
    /*sc_out<sc_uint<8>> inp; // inp & outp are the opposite of fir
    sc_out<bool> inp_vld;
    sc_in<bool> inp_rdy;*/
    sc_in<sc_uint<8>> outp0, outp1, outp2, outp3, outp4, outp5, outp6, outp7, outp8, outp9;/*,outp10,outp11, outp12, outp13, outp14, outp15; // inp & outp are the opposite of fir*/
    sc_in<sc_uint<16>> outp16;/*, outp17, outp18, outp19;*/
    sc_in<bool> outp20, outp21, outp22, outp23, outp24, outp25, outp26, outp27, outp28, outp29, outp30, outp31, outp32, outp33, outp34, outp35, outp36, outp37, outp38, outp39;
    
    // separate source & sink threads
    //void source();
    void sink();

    SC_CTOR(tb)
    {
        //SC_CTHREAD(source, clk.pos());
        SC_METHOD(sink);
        sensitive << outp9;
    }
};