#include <systemc.h>
SC_MODULE(count8)
{
    sc_in<bool> clk, rst;
    sc_out<sc_uint<8>> outp;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void count8_main();

    SC_CTOR(count8)
    {
        SC_CTHREAD(count8_main, clk.pos()); // CTHREAD takes the function to execute as ARG1 and the sensitivity as ARG2
        reset_signal_is(rst, true); // reset condition for the clock thread needs to be on the line immediately after the CTHREAD. reset has two arguments: name of the port, assertion of reset signal (true = high, false =low)
    }
};