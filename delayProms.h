#include <systemc.h>
SC_MODULE(delayProms)
{
    sc_in<bool> chipEnable, outpEnable; //nMOD, MODDIS
    sc_in<sc_uint<8>> address0,address1,address2,address3; //TCB2_7

    sc_out<sc_uint<8>> outp0; //delayData
    sc_out<bool> outp1;

    void func();

    SC_CTOR(delayProms)
    {
        SC_METHOD(func);
        sensitive << chipEnable << address0 << address1 << address2 << address3 <<  outpEnable;
    }
};