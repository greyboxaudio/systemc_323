#include <systemc.h>
SC_MODULE(byteInvertMux)
{
    sc_in<bool> sel;
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<8>> inp1;
    sc_out<sc_uint<8>> outp0;

    void func()
    {
        sc_uint<8> data_a = inp0.read();
        sc_uint<8> data_b = inp1.read();

        if (sel.read() == 0)
        {
            outp0.write(~data_a);
        }
        else
        {
            outp0.write(~data_b);
        }
    }

    SC_CTOR(byteInvertMux)
    {
        SC_METHOD(func);
        sensitive << sel << inp0 << inp1;
    }
};