#include <systemc.h>
SC_MODULE(invert)
{
    sc_in<bool> inp0;
    sc_out<bool> outp0;

    void invert_main();

    SC_CTOR(invert)
    {
        SC_METHOD(invert_main);
        sensitive << inp0;
    }
};