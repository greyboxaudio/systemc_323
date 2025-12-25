#include <systemc.h>
SC_MODULE(writeAddrCount)
{
    sc_in<bool> inp0;
    sc_out<sc_uint<8>> outp0;
    sc_out<sc_uint<8>> outp1;

    sc_uint<16> counterValue{};

    void writeAddrCount_main()
    {
        if (counterValue >= 65536)
        {
            counterValue = 0;
        }
        outp0.write(counterValue & 255);
        outp1.write(counterValue >> 8);
        counterValue += 1;
    }

    SC_CTOR(writeAddrCount)
    {
        SC_METHOD(writeAddrCount_main);
        sensitive << inp0.neg();
    }
};