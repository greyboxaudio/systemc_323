#include <systemc.h>
SC_MODULE(nand)
{
    sc_in<bool> inp0, inp1;
    sc_out<bool> outp0;

    void nand_main();

    SC_CTOR(nand)
    {
        SC_METHOD(nand_main);
        sensitive << inp0 << inp1;
    }
};