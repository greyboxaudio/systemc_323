#include <systemc.h>
SC_MODULE(gainModCtrlProm)
{
    sc_in<bool> chipEnable; //nDAC
    sc_in<bool> outpEnable; //MODDIS
    sc_in<sc_uint<8>> address0; //TCB2_7
    sc_in<sc_uint<8>> address1; //MC5_12
    sc_out<sc_uint<8>> outp0; //gainModCtrlData
    sc_out<bool> outp1; // nGainModPromEnable

    void gainModCtrlProm_main();

    SC_CTOR(gainModCtrlProm)
    {
        SC_METHOD(gainModCtrlProm_main);
        sensitive << address0 << address1 << chipEnable << outpEnable;
    }
};