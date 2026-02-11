#include <systemc.h>
SC_MODULE(latchedMux)
{
    sc_in<bool> clk, sel;
    sc_in<sc_uint<8>> inp0, inp1;
    sc_out<sc_uint<8>> outp0;
    sc_uint<8> data;
    void latchedMux_prc();
    void latchedMux_read();

    SC_CTOR(latchedMux)
    {
        SC_METHOD(latchedMux_read);
        sensitive <<sel << inp0 << inp1;
        SC_METHOD(latchedMux_latch);
        sensitive << clk.neg();
    }
};