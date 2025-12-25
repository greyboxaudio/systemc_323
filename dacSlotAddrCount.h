#include <systemc.h>
SC_MODULE(dacSlotAddrCount)
{
    sc_in<bool> clk;
    sc_in<bool> clr;
    sc_out<sc_uint<8>> outp0;
    sc_uint<8> counterValue{};

    void dacSlotAddrCount_main()
    {
        counterValue += 1;
        if (clr.read() == 0)
        {
            counterValue = 0;
        }
        outp0.write(counterValue);
    }

    SC_CTOR(dacSlotAddrCount)
    {
        SC_METHOD(dacSlotAddrCount_main);
        sensitive << clk.pos() << clr;
    }
};