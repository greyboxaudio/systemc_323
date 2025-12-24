#include <systemc.h>
#include "tb.h"
#include "timer0.h"
#include "timer1.h"
#include "latchedRom0810.h"
#include "latchedRom0811.h"
#include "latchTC1.h"

SC_MODULE(SYSTEM)
{
    //modules
    tb *tb0;
    timer0 *tim0;
    timer1 *tim1;
    rom0810 *rom0;
    rom0811 *rom1;
    latchTC1 *latch0;

    // declare signals
    sc_clock clk_sig;
    sc_signal<bool> rst_sig;
    sc_signal<bool> rom0_enable_sig;
    sc_signal<bool> rom1_enable_sig;
    sc_signal<bool> latch0_enable_sig;
    sc_signal<sc_uint<8>> tim0_outp_sig;
    sc_signal<sc_uint<8>> tim1_outp_sig;
    sc_signal<sc_uint<8>> rom0_outp_sig;
    sc_signal<sc_uint<8>> rom1_outp_sig;
    sc_signal<bool> latch0_outp_sig;
    sc_signal<bool> rom0_outp_sig_nSyncClear;
    
    SC_CTOR(SYSTEM)
        // use copy constructor to define clock
        : clk_sig("clk_sig", 122, SC_NS) //(character pointer string,period units,actual units)
    {
        tb0 = new tb("tb0"); //"new" operator allocates memory space for module
        tb0->clk(clk_sig);   // take clock port of instance tb0 and connect it to clk_sig; -> is a dereference operator
        tb0->rst(rst_sig);
        tb0->outp0(tim0_outp_sig);
        tb0->outp1(rom0_outp_sig);
        tb0->outp2(rom1_outp_sig);
        tb0->outp3(latch0_outp_sig);
        tb0->outp4(tim1_outp_sig);

        tim0 = new timer0("tim0");
        tim0->clk(clk_sig);
        tim0->rst(rst_sig);
        tim0->outp(tim0_outp_sig);

        rom0 = new rom0810("rom0");
        rom0->clk(clk_sig);
        rom0->rst(rst_sig);
        rom0->enable(rom0_enable_sig=true);
        rom0->inp(tim0_outp_sig);
        rom0->outp(rom0_outp_sig);
        rom0->nSyncClear(rom0_outp_sig_nSyncClear);

        rom1 = new rom0811("rom1");
        rom1->clk(clk_sig);
        rom1->rst(rst_sig);
        rom1->enable(rom1_enable_sig=true);
        rom1->inp(tim0_outp_sig);
        rom1->outp(rom1_outp_sig);

        latch0 = new latchTC1("latch0");
        latch0->clk(clk_sig);
        latch0->rst(rst_sig);
        latch0->enable(latch0_enable_sig=true);
        latch0->inp(tim0_outp_sig);
        latch0->outp(latch0_outp_sig);

        tim1 = new timer1("tim1");
        tim1->clk(latch0_outp_sig);
        tim1->rst(rom0_outp_sig_nSyncClear);
        tim1->outp(tim1_outp_sig);
    }
    ~SYSTEM() // destructor
    {
        // free up allocated memory space when the simulation ends
        delete tb0;
        delete tim0;
        delete tim1;
        delete rom0;
        delete rom1;
        delete latch0;
    }
};

SYSTEM *top = NULL; // declare instance pointer called "top" and send that pointer to NULL

int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    top = new SYSTEM("top");
    sc_start(); // start simulation
    return 0;
};