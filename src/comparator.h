#include <systemc.h>
SC_MODULE(comparator)
{
    sc_in<sc_uint<8>> inp0;
    sc_in<sc_uint<8>> inp1;
    sc_out<bool> outp0;

    void func();

    SC_CTOR(comparator)
    {
        SC_METHOD(func);
        sensitive << inp0 << inp1;
    }
};