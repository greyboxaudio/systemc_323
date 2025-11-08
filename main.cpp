#include <systemc.h>
#include "tb.h"
#include "count8.h"

SC_MODULE(SYSTEM)
{
    // instantiate fir and testbench modules
    tb *tb0;
    count8 *counter0;
    // declare signals
    /*sc_signal<sc_uint<8>> inp_sig;
    sc_signal<bool> inp_sig_vld;
    sc_signal<bool> inp_sig_rdy;*/

    sc_signal<sc_uint<8>> outp_sig;
    sc_signal<bool> outp_sig_vld;
    sc_signal<bool> outp_sig_rdy;

    sc_signal<bool> rst_sig;
    sc_clock clk_sig;

    SC_CTOR(SYSTEM)
        // use copy constructor to define clock
        : clk_sig("clk_sig", 122, SC_NS) //(character pointer string,period units,actual units)
    {
        tb0 = new tb("tb0"); //"new" operator allocates memory space for module
        tb0->clk(clk_sig);   // take clock port of instance tb0 and connect it to clk_sig; -> is a dereference operator
        tb0->rst(rst_sig);
        /*tb0->inp(inp_sig);
        tb0->inp_vld(inp_sig_vld);
        tb0->inp_rdy(inp_sig_rdy);*/

        tb0->outp(outp_sig);
        tb0->outp_vld(outp_sig_vld);
        tb0->outp_rdy(outp_sig_rdy);

        counter0 = new count8("counter0");
        counter0->clk(clk_sig);
        counter0->rst(rst_sig);
        /*counter0->inp_vld(inp_sig_vld);
        counter0->inp_rdy(inp_sig_rdy);*/

        counter0->outp(outp_sig);
        counter0->outp_vld(outp_sig_vld);
        counter0->outp_rdy(outp_sig_rdy);
    }
    ~SYSTEM() // destructor
    {
        // free up allocated memory space when the simulation ends
        delete tb0;
        delete counter0;
    }
};

SYSTEM *top = NULL; // declare instance pointer called "top" and send that pointer to NULL

int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    top = new SYSTEM("top");
    sc_start(); // start simulation
    return 0;
};