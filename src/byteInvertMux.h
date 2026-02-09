#include <systemc.h>
SC_MODULE(byteInvertMux)
{
    sc_in<bool> sel;
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<8>> inp1;
    sc_out<sc_uint<8>> outp0;

    void byteInvertMux_main();

    SC_CTOR(byteInvertMux)
    {
        SC_METHOD(byteInvertMux_main);
        sensitive << sel << inp0 << inp1;
    }
};