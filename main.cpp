#include <systemc.h>
#include "tb.h"
#include "count8.h"
#include "rom8.h"
#include "rom_u46.h"

SC_MODULE(SYSTEM)
{
    //modules
    tb *tb0;
    count8 *counter0;
    rom8 *rom0;
    rom_u46 *rom1;
    // declare signals
    sc_signal<sc_uint<8>> inp1_sig;
    sc_signal<sc_uint<8>> inp2_sig;
    sc_signal<sc_uint<8>> outp1_sig;
    sc_signal<sc_uint<8>> outp2_sig;
    sc_signal<sc_uint<8>> outp3_sig;

    sc_signal<bool> rst_sig;
    sc_clock clk_sig;

    SC_CTOR(SYSTEM)
        // use copy constructor to define clock
        : clk_sig("clk_sig", 122, SC_NS) //(character pointer string,period units,actual units)
    {
        tb0 = new tb("tb0"); //"new" operator allocates memory space for module
        tb0->clk(clk_sig);   // take clock port of instance tb0 and connect it to clk_sig; -> is a dereference operator
        tb0->rst(rst_sig);
        tb0->outp(outp3_sig);

        counter0 = new count8("counter0");
        counter0->clk(clk_sig);
        counter0->rst(rst_sig);
        counter0->outp(outp1_sig);

        rom0 = new rom8("rom0");
        rom0->clk(clk_sig);
        rom0->rst(rst_sig);
        rom0->inp(outp1_sig);
        rom0->outp(outp2_sig);

        rom1 = new rom_u46("rom1");
        rom1->clk(clk_sig);
        rom1->rst(rst_sig);
        rom1->inp(outp1_sig);
        rom1->outp(outp3_sig);
    }
    ~SYSTEM() // destructor
    {
        // free up allocated memory space when the simulation ends
        delete tb0;
        delete counter0;
        delete rom0;
        delete rom1;
    }
};

SYSTEM *top = NULL; // declare instance pointer called "top" and send that pointer to NULL

int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    top = new SYSTEM("top");
    sc_start(); // start simulation
    return 0;
};