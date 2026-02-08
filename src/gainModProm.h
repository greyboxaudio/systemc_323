#include <systemc.h>
SC_MODULE(gainModProm)
{
    sc_in<bool> ce; //nDAC
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<16>> inp1;
    sc_out<sc_uint<8>> outp0; //gainModData

    void gainModProm_main();

    SC_CTOR(gainModProm)
    {
        SC_METHOD(gainModProm_main);
        sensitive << ce << inp0 << inp1;
    }
};