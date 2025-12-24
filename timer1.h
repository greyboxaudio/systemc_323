#include <systemc.h>
SC_MODULE(timer1)
{
    sc_in<bool> clk, rst;
    //sc_in<sc_uint<8>> syncClear;
    sc_out<sc_uint<8>> outp0;
    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void timer1_main();

    SC_CTOR(timer1)
    {
        SC_CTHREAD(timer1_main, clk.pos()); // CTHREAD takes the function to execute as ARG1 and the sensitivity as ARG2
        reset_signal_is(rst, false); // reset condition for the clock thread needs to be on the line immediately after the CTHREAD. reset has two arguments: name of the port, assertion of reset signal (true = high, false =low)
    }
};