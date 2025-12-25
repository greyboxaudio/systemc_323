#include <systemc.h>
SC_MODULE(dacSlotAddrCount)
{
    sc_in<bool> clk, clr;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1;

    sc_uint<8> counterValue{};

    void dacSlotAddrCount_main()
    {
        counterValue += 1;
        if (clr.read() == 0)
        {
            counterValue = 0;
        }
        outp0.write(counterValue);
        outp1.write(counterValue[6]);
    }

    SC_CTOR(dacSlotAddrCount)
    {
        SC_METHOD(dacSlotAddrCount_main);
        sensitive << clk.pos() << clr;
    }
};