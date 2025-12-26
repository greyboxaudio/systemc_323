#include <systemc.h>
SC_MODULE(delayProms)
{
    sc_in<bool> chipEnable; //nMOD
    sc_in<bool> outpEnable; //MODDIS
    sc_in<sc_uint<8>> address0; //TCB2_7
    sc_in<sc_uint<8>> address1; //MC5_12
    sc_in<sc_uint<4>> address2; //preDelay
    sc_in<sc_uint<4>> address3; //program
    sc_out<sc_uint<8>> outp0; //delayData

    void delayProms_main();

    SC_CTOR(delayProms)
    {
        SC_METHOD(delayProms_main);
        sensitive << address0 << address1 << address2 << address3 << chipEnable << outpEnable;
    }
};