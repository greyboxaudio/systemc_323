#include <systemc.h>
SC_MODULE(bitInvert)
{
    sc_in<bool> inp0;
    sc_out<bool> outp0;

    void bitInvert_main()
    {
        bool value = inp0.read();
        outp0.write(!value);
    }

    SC_CTOR(bitInvert)
    {
        SC_METHOD(bitInvert_main);
        sensitive << inp0;
    }
};