#include <systemc.h>
SC_MODULE(bitNAND)
{
    sc_in<bool> inp0, inp1;
    sc_out<bool> outp0;

    void bitNAND_main()
    {
        outp0.write(!(inp0.read() & inp1.read()));
    }

    SC_CTOR(bitNAND)
    {
        SC_METHOD(bitNAND_main);
        sensitive << inp0 << inp1;
    }
};