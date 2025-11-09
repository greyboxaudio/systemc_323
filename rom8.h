#include <systemc.h>
SC_MODULE(rom8)
{
    sc_in<sc_uint<8>> inp;
    sc_out<sc_uint<8>> outp;

    void rom8_main();

    SC_CTOR(rom8)
    {
        SC_METHOD(rom8_main);
        sensitive << inp;    
    }
};