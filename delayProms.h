#include <systemc.h>
SC_MODULE(delayProms)
{
    sc_in<bool> ce0, ce1; //nMOD, MODDIS
    sc_in<sc_uint<8>> inp0,inp1,inp2; //TCB2_7
    sc_in<sc_uint<4>> inp3, inp4;
    sc_out<sc_uint<8>> outp0; //delayData

    void dlyData();
    void modData();

    SC_CTOR(delayProms)
    {
        SC_METHOD(dlyData);
        sensitive << ce0 << ce1 << inp0 << inp1 << inp2 << inp3 << inp4;
    }
};