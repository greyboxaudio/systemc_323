#include <systemc.h>
SC_MODULE(byteReg)
{
    sc_in<bool> clk; //nTCB1
    sc_in<sc_uint<8>> inp0; //delayData0
    sc_out<sc_uint<8>> outp0; //delayData1

    void byteReg_main(){
        outp0.write(inp0.read());
    }

    SC_CTOR(byteReg)
    {
        SC_METHOD(byteReg_main);
        sensitive << clk.pos();
    }
};