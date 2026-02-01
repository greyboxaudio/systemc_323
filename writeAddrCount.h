#include <systemc.h>
SC_MODULE(writeAddrCount)
{
    sc_in<bool> clk;
    sc_out<sc_uint<8>> outp0;
    sc_out<sc_uint<8>> outp1;

    sc_uint<16> counterValue{};

    void writeAddrCount_main()
    {
        if (counterValue > 65535)
        {
            counterValue = 0;
        }
        outp0.write(counterValue & 0xff);
        outp1.write(counterValue >> 8);
        counterValue += 1;
    }

    SC_CTOR(writeAddrCount)
    {
        SC_METHOD(writeAddrCount_main);
        sensitive << clk.pos();
    }
};