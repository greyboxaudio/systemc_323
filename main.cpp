#include <systemc.h>
#include "tb.h"
#include "count8.h"
#include "rom8.h"
#include "rom_u46.h"
#include "invert.h"

SC_MODULE(SYSTEM)
{
    //modules
    tb *tb0;
    count8 *counter0;
    rom8 *rom0;
    rom_u46 *rom1;
    invert *invert0;
    // declare signals
    sc_signal<sc_uint<8>> count_outp_sig_u52u53;
    sc_signal<sc_uint<8>> prom_outp_sig_u46;
    sc_signal<sc_uint<8>> prom_outp_sig_u47;
    sc_signal<sc_uint<3>> invert_bitSelect_sig_u66;
    sc_signal<sc_uint<1>> invert_outp_sig_u66;
    sc_signal<sc_uint<8>> latch_outp_sig_u42;
    sc_signal<sc_uint<8>> latch_outp_sig_u43;
    sc_signal<sc_uint<8>> latch_outp_sig_u59;

    sc_signal<bool> rst_sig;
    sc_clock clk_sig;

    SC_CTOR(SYSTEM)
        // use copy constructor to define clock
        : clk_sig("clk_sig", 122, SC_NS) //(character pointer string,period units,actual units)
    {
        tb0 = new tb("tb0"); //"new" operator allocates memory space for module
        tb0->clk(clk_sig);   // take clock port of instance tb0 and connect it to clk_sig; -> is a dereference operator
        tb0->rst(rst_sig);
        tb0->outp0(prom_outp_sig_u46);
        tb0->outp1(prom_outp_sig_u47);

        counter0 = new count8("counter0");
        counter0->clk(clk_sig);
        counter0->rst(rst_sig);
        counter0->outp(count_outp_sig_u52u53);

        rom0 = new rom8("rom0");
        rom0->inp(count_outp_sig_u52u53);
        rom0->outp(prom_outp_sig_u47);

        rom1 = new rom_u46("rom1");
        rom1->inp(count_outp_sig_u52u53);
        rom1->outp(prom_outp_sig_u46);

        invert0 = new invert("invert0");
        invert0->inp(count_outp_sig_u52u53);
        invert_bitSelect_sig_u66 = 1;
        invert0->bitSelect(invert_bitSelect_sig_u66);
        invert0->outp(invert_outp_sig_u66);
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