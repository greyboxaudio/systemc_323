#include <systemc.h>
SC_MODULE(modRateCountProm)
{
    sc_in<sc_uint<4>> inp0, inp1;
    sc_out<sc_uint<8>> outp0;

    void modRateCountProm_main();

    SC_CTOR(modRateCountProm)
    {
        SC_METHOD(modRateCountProm_main);
        sensitive << inp0 << inp1;
    }
};