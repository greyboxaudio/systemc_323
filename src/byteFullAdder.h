#include <systemc.h>
SC_MODULE(byteFullAdder)
{
    sc_in<bool> c0;
    sc_in<sc_uint<8>> inp0, inp1;
    sc_out<bool> c4;
    sc_out<sc_uint<8>> outp0;

    void start_of_simulation(void) override;
    void func();

    SC_CTOR(byteFullAdder)
    {
        SC_METHOD(func);
        sensitive << inp0 << inp1 << c0;
    }
};