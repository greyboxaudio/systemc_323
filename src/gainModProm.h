#include <systemc.h>
SC_MODULE(gainModProm)
{
    sc_in<bool> chipEnable; //nDAC
    sc_in<bool> outpEnable; //MODDIS
    sc_in<sc_uint<8>> address0; //TCB2_7
    sc_in<sc_uint<16>> address1; //MC5_12
    sc_out<sc_uint<8>> outp0; //gainModData

    void gainModProm_main();

    SC_CTOR(gainModProm)
    {
        SC_METHOD(gainModProm_main);
        sensitive << address0 << address1 << chipEnable << outpEnable;
    }
};