#include <systemc.h>
SC_MODULE(sg323)
{
    sc_in<bool> clk, rst;
    sc_in<sc_uint<8>> inp0, inp1, inp2;
    sc_out<sc_uint<16>> outp0;
    sc_out<sc_uint<8>> outp1;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void func();

    SC_CTOR(sg323)
    {
        SC_CTHREAD(func, clk.pos()); // CTHREAD takes the function to execute as ARG1 and the sensitivity as ARG2
        reset_signal_is(rst, true); // reset condition for the clock thread needs to be on the line immediately after the CTHREAD. reset has two arguments: name of the port, assertion of reset signal (true = high, false =low)
    }
};