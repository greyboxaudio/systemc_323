#include <systemc.h>
SC_MODULE(invert)
{
    sc_in<sc_uint<8>> inp;
    sc_in<sc_uint<3>> bitSelect;
    sc_out<sc_uint<1>> outp;

    void invert_main();

    SC_CTOR(invert)
    {
        SC_METHOD(invert_main);
        sensitive << inp;    
    }
};