#include <systemc.h>
SC_MODULE(gainProm)
{
    sc_in<bool> chipEnable;
    sc_in<bool> outpEnable;
    sc_in<sc_uint<8>> address0;
    sc_in<sc_uint<8>> address1;
    sc_in<sc_uint<8>> address2;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1;

    void gainProm_main();

    SC_CTOR(gainProm)
    {
        SC_METHOD(gainProm_main);
        sensitive << address0 << address1 << address2 << chipEnable << outpEnable;
    }
};