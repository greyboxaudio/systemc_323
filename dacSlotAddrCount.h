#include <systemc.h>
SC_MODULE(dacSlotAddrCount)
{
    sc_in<bool> clk, clr;
    sc_out<sc_uint<8>> outp0;
    sc_out<bool> outp1, outp2, outp3, outp4;

    sc_uint<8> counterValue{};

    void dacSlotAddrCount_main()
    {
        if (clr.read() == 0)
        {
            counterValue = 0;
        }
        outp0.write(counterValue);
        outp1.write(counterValue[5].to_bool());
        outp3.write(counterValue[5].to_bool());
        outp4.write(!counterValue[5].to_bool());
        outp2.write(counterValue[0].to_bool());
        counterValue += 1;
    }

    SC_CTOR(dacSlotAddrCount)
    {
        SC_METHOD(dacSlotAddrCount_main);
        sensitive << clk.pos() << clr;
    }
};