#include <systemc.h>
SC_MODULE(invert)
{
    sc_in<bool> inp0;
    sc_out<bool> outp0;

    void invert_main()
    {
        bool a = inp0.read();
        outp0.write(!a);
    }

    SC_CTOR(invert)
    {
        SC_METHOD(invert_main);
        sensitive << inp0;
    }
};