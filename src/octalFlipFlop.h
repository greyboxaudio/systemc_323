#include <systemc.h>
SC_MODULE(octalFlipFlop)
{
    sc_in<bool> clk, inp0, inp1, inp2, inp3, inp4, inp5, inp6, inp7;
    sc_out<bool> outp0, outp1, outp2, outp3, outp4, outp5, outp6, outp7;

    void func();

    SC_CTOR(octalFlipFlop)
    {
        SC_METHOD(func);
        sensitive << clk.pos();
    }
};