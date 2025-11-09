#include <systemc.h>
SC_MODULE(rom_u46)
{
    sc_in<sc_uint<8>> inp;
    sc_out<sc_uint<8>> outp;

    void rom8_main();

    SC_CTOR(rom_u46)
    {
        SC_METHOD(rom8_main);
        sensitive << inp;
    }
};