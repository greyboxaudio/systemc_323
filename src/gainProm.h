#include <systemc.h>
SC_MODULE(gainProm)
{
    sc_in<bool> ce;
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<4>> inp1, inp2;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1;

    void gainProm_main();

    SC_CTOR(gainProm)
    {
        SC_METHOD(gainProm_main);
        sensitive << ce << inp0 << inp1 << inp2;
    }
};