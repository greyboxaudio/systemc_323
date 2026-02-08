#include <systemc.h>
SC_MODULE(comparator)
{
    sc_in<sc_uint<8>> inp0, inp1;
    sc_out<bool> outp0;

    void comparator_main();

    SC_CTOR(comparator)
    {
        SC_METHOD(comparator_main);
        sensitive << inp0 << inp1;
    }
};