#include <systemc.h>
SC_MODULE(octalFlipFlop)
{
    sc_in<bool> clk, inp0, inp1, inp2, inp3, inp4, inp5, inp6, inp7;
    sc_out<bool> outp0, outp1, outp2, outp3, outp4, outp5, outp6, outp7;

    void func(){
        outp0.write(inp0.read());
        outp1.write(inp1.read());
        outp2.write(inp2.read());
        outp3.write(inp3.read());
        outp4.write(inp4.read());
        outp5.write(inp5.read());
        outp6.write(inp6.read());
        outp7.write(inp7.read());
    }

    SC_CTOR(octalFlipFlop)
    {
        SC_METHOD(func);
        sensitive << clk.pos();
    }
};