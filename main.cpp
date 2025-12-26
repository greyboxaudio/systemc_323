#include <systemc.h>
#include "tb.h"
#include "timer0.h"
#include "dacSlotAddrCount.h"
#include "timingProms.h"
#include "byteSplitter.h"
#include "modRateCount.h"
#include "bitFlipFlop.h"
#include "modCount.h"
#include "bitInvert.h"
#include "delayProms.h"
#include "writeAddrCount.h"
#include "byteReg.h"
#include "byteInvertMux.h"
#include "byteFullAdder.h"
#include "addressMangle.h"

SC_MODULE(SYSTEM)
{
    //modules
    tb *tb0;
    timer0 *tim0;
    timingProms *timingProms0;
    byteSplitter *split0;
    byteSplitter *split1;
    dacSlotAddrCount *count0;
    modRateCount *modRateCount0;
    bitFlipFlop *bitFlipFlop0;
    bitFlipFlop *bitFlipFlop1;
    modCount *modCount0;
    bitInvert *bitInvert0;
    bitInvert *bitInvert1;
    delayProms *delayProms0;
    writeAddrCount *writeAddrCount0;
    byteReg *byteReg0;
    byteInvertMux *byteInvertMux0;
    byteFullAdder *byteFullAdder0;
    addressMangle *addressMangle0;

    // declare signals
    sc_clock clk_sig;
    sc_signal<bool> rst_sig;
    sc_signal<sc_uint<4>> program, ratlvl, decay, preDelay;
    sc_signal<sc_uint<8>> TC0_7, TCB2_7;
    sc_signal<sc_uint<8>> rom0_outp_sig, rom1_outp_sig;
    sc_signal<bool> nTCB1;
    sc_signal<bool> nSyncClear;
    sc_signal<bool> DAC;
    sc_signal<bool> DACEN;
    sc_signal<bool> CAS;
    sc_signal<bool> RAS;
    sc_signal<bool> SARCK;
    sc_signal<bool> nS;
    sc_signal<bool> nMOD;
    sc_signal<bool> nDACX;
    sc_signal<bool> ISH;
    sc_signal<bool> nER;
    sc_signal<bool> nEL;
    sc_signal<bool> nEF;
    sc_signal<bool> nET;
    sc_signal<bool> MSBE;
    sc_signal<bool> LSBE;
    sc_signal<bool> TCB2, TCB7, nTCB7, TCB7A;
    sc_signal<bool> SNMODEN, MODDIS;
    sc_signal<bool> carry, MCCK;
    sc_signal<sc_uint<16>> MC0_12;
    sc_signal<sc_uint<8>> MC5_12;
    sc_signal<sc_uint<8>> nROW, nCOLUMN, writeAddrData;
    sc_signal<bool> c0, c4;
    sc_signal<sc_uint<8>> delayData0, delayData1;
    sc_signal<sc_uint<8>> debug0, debug1, debug2, debug3, debug4;
    sc_signal<bool> pullHigh, pullLow;
    sc_signal<sc_uint<8>> address0, address1;
    
    SC_CTOR(SYSTEM)
        // use copy constructor to define clock
        : clk_sig("clk_sig", 122, SC_NS) //(character pointer string,period units,actual units)
    {
        program = 0;
        preDelay = 0;
        decay = 0;
        pullHigh = 1;
        pullLow = 0;

        tb0 = new tb("tb0"); //"new" operator allocates memory space for module
        tb0->clk(clk_sig);   // take clock port of instance tb0 and connect it to clk_sig; -> is a dereference operator
        tb0->rst(rst_sig);
        tb0->outp0(TC0_7);
        tb0->outp1(MC5_12);
        tb0->outp2(delayData1);
        tb0->outp3(writeAddrData);
        tb0->outp4(address0);
        tb0->outp5(address1);
        tb0->outp6(c0);
        tb0->outp7(c4);

        tim0 = new timer0("tim0");
        tim0->clk(clk_sig);
        tim0->rst(rst_sig);
        tim0->outp0(TC0_7);

        timingProms0 = new timingProms("rom0");
        timingProms0->clk(clk_sig);
        timingProms0->rst(rst_sig);
        timingProms0->inp0(TC0_7);
        timingProms0->outp0(rom0_outp_sig);
        timingProms0->outp1(rom1_outp_sig);
        timingProms0->outp2(nTCB1);

        split0 = new byteSplitter("split0");
        split0->inp0(rom0_outp_sig);
        split0->outp0(nSyncClear);
        split0->outp1(DAC);
        split0->outp2(DACEN);
        split0->outp3(CAS);
        split0->outp4(RAS);
        split0->outp5(SARCK);
        split0->outp6(nS);
        split0->outp7(nMOD);

        split1 = new byteSplitter("split1");
        split1->inp0(rom1_outp_sig);
        split1->outp0(nDACX);
        split1->outp1(ISH);
        split1->outp2(nER);
        split1->outp3(nEL);
        split1->outp4(nEF);
        split1->outp5(nET);
        split1->outp6(MSBE);
        split1->outp7(LSBE);

        count0 = new dacSlotAddrCount("count0");
        count0->clk(nTCB1);
        count0->clr(nSyncClear);
        count0->outp0(TCB2_7);
        count0->outp1(TCB7);
        count0->outp2(TCB2);

        writeAddrCount0 = new writeAddrCount("writeAddrCount0");
        writeAddrCount0->clk(TCB7A);
        writeAddrCount0->outp0(nROW);
        writeAddrCount0->outp1(nCOLUMN);

        byteInvertMux0 = new byteInvertMux("byteInvertMux0");
        byteInvertMux0->sel(TCB2);
        byteInvertMux0->inp0(nROW);
        byteInvertMux0->inp1(nCOLUMN);
        byteInvertMux0->outp0(writeAddrData);

        bitInvert0 = new bitInvert("bitInvert0");
        bitInvert0->inp0(TCB7);
        bitInvert0->outp0(nTCB7);

        bitInvert1 = new bitInvert("bitInvert1");
        bitInvert1->inp0(nTCB7);
        bitInvert1->outp0(TCB7A);

        modRateCount0 = new modRateCount("modRateCount0");
        modRateCount0->inp0(ratlvl);
        modRateCount0->inp1(program);
        modRateCount0->clk(TCB7);
        modRateCount0->outp0(SNMODEN);
        modRateCount0->outp1(MODDIS);
        modRateCount0->outp2(carry);

        //modCountClk
        bitFlipFlop0 = new bitFlipFlop("bitFlipFlop0");
        bitFlipFlop0->clk(nTCB7);
        bitFlipFlop0->clr(pullHigh);
        bitFlipFlop0->inp0(carry);
        bitFlipFlop0->outp0(MCCK);

        modCount0 = new modCount("modCount0");
        modCount0->clk(MCCK);
        modCount0->outp0(MC0_12);
        modCount0->outp1(MC5_12);

        byteReg0 = new byteReg("byteReg0");
        byteReg0->clk(nTCB1);
        byteReg0->inp0(delayData0);
        byteReg0->outp0(delayData1);

        delayProms0 = new delayProms("delayProms0");
        delayProms0->nMOD(nMOD);
        delayProms0->MODDIS(MODDIS);
        delayProms0->TCB2_7(TCB2_7);
        delayProms0->MC5_12(MC5_12);
        delayProms0->preDelay(preDelay);
        delayProms0->program(program);
        delayProms0->outp0(delayData0);

        //rowCarryOutLatch
        bitFlipFlop1 = new bitFlipFlop("bitFlipFlop1");
        bitFlipFlop1->clk(nTCB1);
        bitFlipFlop1->clr(RAS);
        bitFlipFlop1->inp0(c4);
        bitFlipFlop1->outp0(c0);

        byteFullAdder0 = new byteFullAdder("byteFullAdder0");
        byteFullAdder0->inp0(writeAddrData);
        byteFullAdder0->inp1(delayData1);
        byteFullAdder0->cIn(c0);
        byteFullAdder0->outp0(address0);
        byteFullAdder0->cOut(c4);

        addressMangle0 = new addressMangle("addressMangle0");
        addressMangle0->inp0(address0);
        addressMangle0->outp0(address1);
    }
    ~SYSTEM() // destructor
    {
        // free up allocated memory space when the simulation ends
        delete tb0;
        delete tim0;
        delete count0;
        delete split0;
        delete split1;
        delete timingProms0;
        delete modRateCount0;
        delete bitFlipFlop0;
        delete bitFlipFlop1;
        delete modCount0;
        delete bitInvert0;
        delete delayProms0;
        delete writeAddrCount0;
        delete byteReg0;
        delete byteInvertMux0;
        delete byteFullAdder0;
        delete addressMangle0;
    }
};

SYSTEM *top = NULL; // declare instance pointer called "top" and send that pointer to NULL

int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    top = new SYSTEM("top");
    sc_start(); // start simulation
    return 0;
};