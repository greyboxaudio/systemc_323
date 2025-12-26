#include <systemc.h>
SC_MODULE(bitFlipFlop)
{
    sc_in<bool> clk, clr, inp0;
    sc_out<bool> outp0;

    void bitFlipFlop_main(){
        if (clr.read() == 1)
        {
            outp0.write(inp0.read());
        }else{
            outp0.write(0);
        }
    }

    SC_CTOR(bitFlipFlop)
    {
        SC_METHOD(bitFlipFlop_main);
        sensitive << clk.pos();
    }
};