#include <systemc.h>
#include "tb323.h"
#include "sg323.h"

SC_MODULE(SYSTEM)
{
    //modules
    tb323 *tb0;
    sg323 *sg0;

    // declare signals
    sc_clock clk_sig;
    sc_signal<bool> rst_sig;
    sc_signal<sc_uint<8>> program0, decaytime0, preDelay0, ratlvl;
    sc_signal<sc_uint<8>> gain;
    sc_signal<sc_uint<16>> address;
    
    SC_CTOR(SYSTEM)
        // use copy constructor to define clock
        : clk_sig("clk_sig", 122, SC_NS) //(character pointer string,period units,actual units)
    {
        program0 = 16;
        preDelay0 = 9;
        decaytime0 = 16;
        ratlvl = 0;

        tb0 = new tb323("tb0"); //"new" operator allocates memory space for module
        tb0->clk(clk_sig);   // take clock port of instance tb0 and connect it to clk_sig; -> is a dereference operator
        tb0->rst(rst_sig);
        tb0->outp0(address);
        tb0->outp1(gain);

        sg0 = new sg323("sg323");
        sg0->clk(clk_sig);
        sg0->rst(rst_sig);
        sg0->inp0(program0);
        sg0->inp1(preDelay0);
        sg0->inp2(decaytime0);
        sg0->outp0(address);
        sg0->outp1(gain);
    }
    ~SYSTEM() // destructor
    {
        // free up allocated memory space when the simulation ends
        delete tb0;
        delete sg0;
    }
};

SYSTEM *top = NULL; // declare instance pointer called "top" and send that pointer to NULL

int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    top = new SYSTEM("top");
    sc_start(); // start simulation
    return 0;
};