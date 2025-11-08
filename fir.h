#include <systemc.h>
SC_MODULE(fir)
{
    sc_in<bool> clk, rst;
    sc_in<sc_int<16>> inp;
    sc_out<sc_int<16>> outp;
    sc_in<bool> inp_vld, outp_rdy;
    sc_out<bool> inp_rdy, outp_vld;

    // keep the module down to declaring ports, threads and constructors and leave all the behavioural functionality to other files
    void fir_main();

    SC_CTOR(fir)
    {
        SC_CTHREAD(fir_main, clk.pos()); // CTHREAD takes the function to execute as ARG1 and the sensitivity as ARG2
        reset_signal_is(rst, true);      // reset condition for the clock thread needs to be on the line immediately after the CTHREAD. reset has two arguments: name of the port, assertion of reset signal (true = high, false =low)
    }
};