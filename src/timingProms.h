#include <systemc.h>
SC_MODULE(timingProms)
{
    sc_in<sc_uint<8>> inp0;
    sc_out<bool> outp0, outp1, outp2, outp3, outp4, outp5, outp6, outp7;
    sc_out<bool> outp8, outp9, outp10, outp11, outp12, outp13, outp14, outp15;

    void start_of_simulation( void ) override;
    void func();

    SC_CTOR(timingProms)
    {
        SC_METHOD(func);
        sensitive << inp0;
        dont_initialize();
    }
};