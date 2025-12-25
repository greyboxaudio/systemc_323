#include <systemc.h>
SC_MODULE(modCountClk)
{
    sc_in<bool> clk, inp0;
    sc_out<bool> outp0;

    void modCountClk_main(){
        outp0.write(inp0.read());
    }

    SC_CTOR(modCountClk)
    {
        SC_METHOD(modCountClk_main);
        sensitive << clk.pos();
    }
};