#include <systemc.h>
SC_MODULE(byteReg)
{
    sc_in<bool> clk;
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<8>> outp0;

    void byteReg_main(){
        outp0.write(inp0.read());
    }

    SC_CTOR(byteReg)
    {
        SC_METHOD(byteReg_main);
        sensitive << clk.pos();
    }
};