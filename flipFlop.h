#include <systemc.h>
SC_MODULE(flipFlop)
{
    sc_in<bool> clk, clr, inp0;
    sc_out<bool> outp0, outp1;

    void flipFlop_main(){
        if (clr.read() == 1)
        {
            bool q = inp0.read();
            outp0.write(q);
            outp1.write(~q);
        }
    }

    SC_CTOR(flipFlop)
    {
        SC_METHOD(flipFlop_main);
        sensitive << clk.pos();
    }
};