#include <systemc.h>
SC_MODULE(bitInvert)
{
    sc_in<bool> inp0;
    sc_out<bool> outp0;

    bool value{};
    void bitInvert_main()
    {
        outp0.write(!value);
        value = inp0.read();
    }

    SC_CTOR(bitInvert)
    {
        SC_METHOD(bitInvert_main);
        sensitive << inp0;
    }
};