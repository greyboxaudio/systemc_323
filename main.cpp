#include <systemc.h>
#include "tb.h"
#include "timer0.h"
#include "dacSlotAddrCount.h"
#include "timingProms.h"
#include "byteSplitter.h"
#include "modRateCountProm.h"
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
#include "gainModCtrlProm.h"
#include "gainModProm.h"
#include "gainProm.h"
#include "bitNAND.h"
#include "comparator.h"
#include "latchedMux.h"
#include "controlLogic.h"
#include "dram.h"

SC_MODULE(SYSTEM)
{
    //modules
    tb *tb0;
    timer0 *tim0;
    timingProms *timingProms0;
    byteSplitter *split0;
    byteSplitter *split1;
    dacSlotAddrCount *count0;
    modRateCountProm *modRateCountProm0;
    modRateCount *modRateCount0;
    bitFlipFlop *bitFlipFlop0;
    bitFlipFlop *bitFlipFlop1;
    bitFlipFlop *bitFlipFlop2;
    modCount *modCount0;
    bitInvert *bitInvert0;
    bitInvert *bitInvert1;
    bitInvert *bitInvert2;
    delayProms *delayProms0;
    writeAddrCount *writeAddrCount0;
    byteReg *byteReg0;
    byteInvertMux *byteInvertMux0;
    byteFullAdder *byteFullAdder0;
    addressMangle *addressMangle0;
    gainModCtrlProm *gainModCtrlProm0;
    gainModProm *gainModProm0;
    gainProm *gainProm0;
    bitNAND *bitNAND0;
    bitNAND *bitNAND1;
    bitNAND *bitNAND2;
    bitNAND *bitNAND3;
    comparator *comparator0;
    latchedMux *latchedMux0;
    controlLogic *controlLogic0;
    dram *dram0;

    // declare signals
    sc_clock clk_sig;
    sc_signal<bool> rst_sig;
    sc_signal<sc_uint<8>> program0, decaytime0, preDelay0, program1, preDelay1, decaytime1, ratlvl;
    sc_signal<sc_uint<8>> rom0_outp_sig, rom1_outp_sig, modRateCountData;
    sc_signal<bool> nSyncClear,DAC, DACEN,RAS, CAS,SARCK,nS,nMOD;
    sc_signal<bool> nDACX,ISH,nER,nEL,nEF,nET,MSBE,LSBE;
    sc_signal<bool> nDAC,nTCB1, nDDTCB1, TCB1,TCB2, TCB7, nTCB7, TCB7A;
    sc_signal<bool> SNMODEN, MODDIS;
    sc_signal<bool> carry, MCCK;
    sc_signal<sc_uint<16>> MC0_12;
    sc_signal<sc_uint<8>> TC0_7, TCB2_7,MC5_12;
    sc_signal<sc_uint<8>> nROW, nCOLUMN, writeAddrData;
    sc_signal<bool> c0, c4;
    sc_signal<sc_uint<8>> delayData0, delayData1;
    sc_signal<sc_uint<16>> debug0, debug1;
    sc_signal<sc_uint<8>> debug2, debug3, debug4;
    sc_signal<bool> pullHigh, pullLow;
    sc_signal<sc_uint<8>> address0, address1;
    sc_signal<sc_uint<16>> address2;
    sc_signal<sc_uint<8>> gainModCtrlData, gainModData, gainData, gain;
    sc_signal<bool> nGainModPromEnable, gainModPromEnabled, nGSN, nGainLatch, bitFlipFlop2outp, nSelectA, compOutp0;
    
    
    SC_CTOR(SYSTEM)
        // use copy constructor to define clock
        : clk_sig("clk_sig", 122, SC_NS) //(character pointer string,period units,actual units)
    {
        program0 = 16;
        preDelay0 = 9;
        decaytime0 = 16;
        ratlvl = 0;
        pullHigh = 1;
        pullLow = 0;

        tb0 = new tb("tb0"); //"new" operator allocates memory space for module
        tb0->clk(clk_sig);   // take clock port of instance tb0 and connect it to clk_sig; -> is a dereference operator
        tb0->rst(rst_sig);
        tb0->outp0(TC0_7);
        tb0->outp1(TCB2_7);
        tb0->outp2(MC5_12);
        tb0->outp3(delayData0);
        tb0->outp16(address2);
        tb0->outp20(nSyncClear);
        tb0->outp21(DAC);
        tb0->outp22(DACEN);
        tb0->outp23(CAS);
        tb0->outp24(RAS);
        tb0->outp25(SARCK);
        tb0->outp26(nS);
        tb0->outp27(nMOD);
        tb0->outp28(nDACX);
        tb0->outp29(ISH);
        tb0->outp30(nER);
        tb0->outp31(nEL);
        tb0->outp32(nEF);
        tb0->outp33(nET);
        tb0->outp34(MSBE);
        tb0->outp35(LSBE);
        tb0->outp36(nDAC);
        tb0->outp37(nTCB1);
        tb0->outp38(TCB7);
        tb0->outp39(pullLow);

        controlLogic0 = new controlLogic("controlLogic0");
        controlLogic0->programInp(program0);
        controlLogic0->predelayInp(preDelay0);
        controlLogic0->decaytimeInp(decaytime0);
        controlLogic0->programOutp(program1);
        controlLogic0->predelayOutp(preDelay1);
        controlLogic0->decaytimeOutp(decaytime1);

        tim0 = new timer0("tim0");
        tim0->clk(clk_sig);
        tim0->rst(rst_sig);
        tim0->outp0(TC0_7);

        timingProms0 = new timingProms("rom0");
        timingProms0->clk(clk_sig);
        timingProms0->rst(rst_sig);        
        timingProms0->inp0(TC0_7);
        timingProms0->outp0(nSyncClear);
        timingProms0->outp1(DAC);
        timingProms0->outp2(DACEN);
        timingProms0->outp3(CAS);
        timingProms0->outp4(RAS);
        timingProms0->outp5(SARCK);
        timingProms0->outp6(nS);
        timingProms0->outp7(nMOD);
        timingProms0->outp8(nDACX);
        timingProms0->outp9(ISH);
        timingProms0->outp10(nER);
        timingProms0->outp11(nEL);
        timingProms0->outp12(nEF);
        timingProms0->outp13(nET);
        timingProms0->outp14(MSBE);
        timingProms0->outp15(LSBE);
        timingProms0->outp16(nDAC);
        timingProms0->outp17(nTCB1);
        timingProms0->outp18(nDDTCB1);

        count0 = new dacSlotAddrCount("count0");
        count0->clk(nDDTCB1);
        count0->clr(nSyncClear);
        count0->outp0(TCB2_7);
        count0->outp1(TCB7);
        count0->outp2(TCB2);
        count0->outp3(TCB7A);
        count0->outp4(nTCB7);

        writeAddrCount0 = new writeAddrCount("writeAddrCount0");
        writeAddrCount0->clk(TCB7A);
        writeAddrCount0->outp0(nROW);
        writeAddrCount0->outp1(nCOLUMN);

        byteInvertMux0 = new byteInvertMux("byteInvertMux0");
        byteInvertMux0->sel(TCB2);
        byteInvertMux0->inp0(nROW);
        byteInvertMux0->inp1(nCOLUMN);
        byteInvertMux0->outp0(writeAddrData);
/*
        bitInvert0 = new bitInvert("bitInvert0");
        bitInvert0->inp0(TCB7);
        bitInvert0->outp0(nTCB7);

        bitInvert1 = new bitInvert("bitInvert1");
        bitInvert1->inp0(nTCB7);
        bitInvert1->outp0(TCB7A);
*/
        modRateCountProm0 = new modRateCountProm("modRateCountProm0");
        modRateCountProm0->address0(ratlvl);
        modRateCountProm0->address1(program1);
        modRateCountProm0->outp0(modRateCountData);
        modRateCountProm0->outp1(SNMODEN);
        modRateCountProm0->outp2(MODDIS);

        modRateCount0 = new modRateCount("modRateCount0");
        modRateCount0->clk(TCB7);
        modRateCount0->inp0(modRateCountData);
        modRateCount0->outp0(carry);

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

        gainModCtrlProm0 = new gainModCtrlProm("gainModCtrlProm0");
        gainModCtrlProm0->chipEnable(nDAC);
        gainModCtrlProm0->outpEnable(pullLow);
        //gainModCtrlProm0->outpEnable(MODDIS);
        gainModCtrlProm0->address0(TCB2_7);
        gainModCtrlProm0->address1(MC5_12);
        gainModCtrlProm0->outp0(gainModCtrlData);
        gainModCtrlProm0->outp1(nGainModPromEnable);

        bitNAND2 = new bitNAND("bitNAND2");
        bitNAND2->inp0(nGainModPromEnable);
        bitNAND2->inp1(pullHigh);
        bitNAND2->outp0(gainModPromEnabled);

        gainModProm0 = new gainModProm("gainModProm0");
        gainModProm0->chipEnable(nGainModPromEnable);
        gainModProm0->outpEnable(pullLow);
        gainModProm0->address0(gainModCtrlData);
        gainModProm0->address1(MC0_12);
        gainModProm0->outp0(gainModData);

        gainProm0 = new gainProm("gainProm0");
        gainProm0->chipEnable(nDACX);
        gainProm0->outpEnable(nDACX);
        gainProm0->address0(TCB2_7);
        gainProm0->address1(decaytime1);
        gainProm0->address2(program1);
        gainProm0->outp0(gainData);
        gainProm0->outp1(nGSN);

        comparator0 = new comparator("comparator0");
        comparator0->inp0(gainModData);
        comparator0->inp1(gainData);
        comparator0->outp0(compOutp0);

        bitNAND3 = new bitNAND("bitNAND3");
        bitNAND3->inp0(gainModPromEnabled);
        bitNAND3->inp1(compOutp0);
        bitNAND3->outp0(nSelectA);

        bitNAND0 = new bitNAND("bitNAND0");
        bitNAND0->inp0(nTCB1);
        bitNAND0->inp1(nTCB1);
        bitNAND0->outp0(TCB1);

        bitFlipFlop2 = new bitFlipFlop("bitFlipFlop2");
        bitFlipFlop2->clk(TCB1);
        bitFlipFlop2->clr(pullHigh);
        bitFlipFlop2->inp0(TCB2);
        bitFlipFlop2->outp0(bitFlipFlop2outp);

        bitNAND1 = new bitNAND("bitNAND1");
        bitNAND1->inp0(nTCB1);
        bitNAND1->inp1(bitFlipFlop2outp);
        bitNAND1->outp0(nGainLatch);

        latchedMux0 = new latchedMux("latchedMux0");
        latchedMux0->clk(nGainLatch);
        latchedMux0->sel(nSelectA);
        latchedMux0->inp0(gainModData);
        latchedMux0->inp1(gainData);
        latchedMux0->outp0(gain);

        delayProms0 = new delayProms("delayProms0");
        delayProms0->chipEnable(nMOD);
        delayProms0->outpEnable(pullLow);
        //delayProms0->outpEnable(MODDIS);
        delayProms0->address0(TCB2_7);
        delayProms0->address1(MC5_12);
        delayProms0->address2(preDelay1);
        delayProms0->address3(program1);
        delayProms0->outp0(delayData0);
        delayProms0->outp1(debug0);
        delayProms0->outp2(debug1);
        delayProms0->outp3(debug2);
        delayProms0->outp4(debug3);

        byteReg0 = new byteReg("byteReg0");
        byteReg0->clk(nTCB1);
        byteReg0->inp0(delayData0);
        byteReg0->outp0(delayData1);

        byteFullAdder0 = new byteFullAdder("byteFullAdder0");
        byteFullAdder0->inp0(writeAddrData);
        byteFullAdder0->inp1(delayData1);
        byteFullAdder0->cIn(c0);
        byteFullAdder0->outp0(address0);
        byteFullAdder0->cOut(c4);

        //rowCarryOutLatch
        bitFlipFlop1 = new bitFlipFlop("bitFlipFlop1");
        bitFlipFlop1->clk(nTCB1);
        bitFlipFlop1->clr(RAS);
        bitFlipFlop1->inp0(c4);
        bitFlipFlop1->outp0(c0);

        addressMangle0 = new addressMangle("addressMangle0");
        addressMangle0->inp0(address0);
        addressMangle0->outp0(address1);

        dram0 = new dram("dram0");
        dram0->ras(RAS);
        dram0->cas(CAS);
        dram0->inp0(address1);
        dram0->outp0(address2);
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
        delete modRateCountProm0;
        delete modRateCount0;
        delete bitFlipFlop0;
        delete bitFlipFlop1;
        delete modCount0;
        delete bitInvert0;
        delete bitInvert1;
        delete bitInvert2;
        delete delayProms0;
        delete writeAddrCount0;
        delete byteReg0;
        delete byteInvertMux0;
        delete byteFullAdder0;
        delete addressMangle0;
        delete gainModCtrlProm0;
        delete gainModProm0;
        delete gainProm0;
        delete bitNAND0;
        delete bitNAND1;
        delete bitNAND2;
        delete bitNAND3;
        delete comparator0;
        delete latchedMux0;
        delete controlLogic0;
        delete dram0;
    }
};

SYSTEM *top = NULL; // declare instance pointer called "top" and send that pointer to NULL

int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    top = new SYSTEM("top");
    sc_start(); // start simulation
    return 0;
};