#include <systemc.h>
SC_MODULE(modCount)
{
    sc_in<bool> clk;
    sc_out<sc_uint<16>> outp0;
    sc_out<sc_uint<8>> outp1;

    sc_uint<16> counterValue{};

    void modCount_main()
    {
        outp0.write(counterValue);
        outp1.write(counterValue >> 5);
        if (counterValue <= 8192)
        {
            counterValue += 1;
        }
        else
        {
            counterValue = 0;
        }
    }

    SC_CTOR(modCount)
    {
        SC_METHOD(modCount_main);
        sensitive << clk.pos();
    }
};