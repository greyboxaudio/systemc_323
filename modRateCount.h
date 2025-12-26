#include <systemc.h>
SC_MODULE(modRateCount)
{
    sc_in<bool> clk;
    sc_in<sc_uint<8>> inp0;
    sc_out<bool> outp0;

    sc_uint<8> counterValue{};
    bool carry{};

    void func(){
        carry = counterValue >> 4;
        if (carry == 1)
        {
            counterValue = inp0.read() & 15;
        }
        outp0.write(carry);
        counterValue += 1;
    }

    SC_CTOR(modRateCount)
    {
        SC_METHOD(func);
        sensitive << clk.pos();
    }
};