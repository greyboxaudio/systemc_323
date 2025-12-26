#include <systemc.h>
SC_MODULE(delayData)
{
    sc_in<bool> nMOD; //nMOD
    sc_in<bool> MODDIS; //MODDIS
    sc_in<sc_uint<8>> TCB2_7; //TCB2_7
    sc_in<sc_uint<8>> MC5_12; //MC5_12
    sc_in<sc_uint<4>> preDelay; //preDelay
    sc_in<sc_uint<4>> program; //program
    sc_out<sc_uint<8>> outp0; //ADDRESS
    sc_out<sc_uint<8>> outp1;
    sc_out<sc_uint<8>> outp2;
    sc_out<sc_uint<8>> outp3;
    sc_out<sc_uint<8>> outp4;

    void delayData_main();

    SC_CTOR(delayData)
    {
        SC_METHOD(delayData_main);
        sensitive << TCB2_7 << MC5_12 << preDelay << program << nMOD << MODDIS;
    }
};