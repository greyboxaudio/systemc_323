#include <systemc.h>
SC_MODULE(byteReg)
{
    sc_in<bool> clk;
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<8>> outp0;

    sc_uint<8> data;

    void byteReg_read(void);
    void byteReg_latch(void);

    SC_CTOR(byteReg)
    {
        SC_METHOD(byteReg_read);
        sensitive << inp0;
        SC_METHOD(byteReg_latch);
        sensitive << clk.pos();
    }
};