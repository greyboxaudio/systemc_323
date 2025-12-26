#include <systemc.h>
SC_MODULE(delayDataReg)
{
    sc_in<bool> inp0; //ntCB1
    sc_in<bool> inp1; //nMOD
    sc_in<bool> inp2; //MODDIS
    sc_in<sc_uint<8>> inp3; //TCB2_7
    sc_in<sc_uint<8>> inp4; //MC5_12
    sc_in<sc_uint<4>> inp5; //preDelay
    sc_in<sc_uint<4>> inp6; //program
    sc_in<sc_uint<8>> inp7; //nROW
    sc_in<sc_uint<8>> inp8; //nCOL
    sc_in<bool> inp9; //RAS
    sc_out<sc_uint<8>> outp0; //ADDRESS
    sc_out<sc_uint<8>> outp1;
    sc_out<sc_uint<8>> outp2;
    sc_out<sc_uint<8>> outp3;
    sc_out<sc_uint<8>> outp4;

    void delayDataReg_main();

    SC_CTOR(delayDataReg)
    {
        SC_METHOD(delayDataReg_main);
        sensitive << inp0.pos();
    }
};