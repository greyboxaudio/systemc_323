#include <systemc.h>
SC_MODULE(gainModCtrlProm)
{
    sc_in<bool> ce; //nDAC
    sc_in<sc_uint<8>> inp0, inp1; //TCB3_7, MC6_12
    sc_out<sc_uint<8>> outp0; //gainModCtrlData
    sc_out<bool> outp1; // nGainModPromEnable

    void gainModCtrlProm_main();

    SC_CTOR(gainModCtrlProm)
    {
        SC_METHOD(gainModCtrlProm_main);
        sensitive << ce << inp0 << inp1;
    }
};