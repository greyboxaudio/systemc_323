#include <systemc.h>
SC_MODULE(byteReg)
{
    sc_in<bool> clk;
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<8>> outp0;
    sc_uint<8> data;

    void latch(){
        outp0.write(data);
    }
    void read(){
        data = inp0.read();
    }

    SC_CTOR(byteReg)
    {
        SC_METHOD(latch);
        sensitive << clk.pos();
        SC_METHOD(read);
        sensitive << inp0;
    }
};