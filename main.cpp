#include <systemc.h>
#include "tb.h"
#include "timer0.h"
#include "timer1.h"
#include "timingProms.h"
#include "octalFlipFlop.h"
#include "dacSlotAddrCount.h"
#include "controlLogic.h"
#include "invert.h"
#include "flipFlop.h"
#include "modRateCountProm.h"
#include "modRateCount.h"
/*
#include "byteSplitter.h"

#include "bitFlipFlop.h"
#include "modCount.h"
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
#include "dram.h"
*/

SC_MODULE(SYSTEM)
{
    // modules
    tb *tb0;
    controlLogic *controlLogic0;
    timer0 *tim0;
    timer1 *tim1;
    timingProms *timingProms0;
    octalFlipFlop *octalFlipFlop0,*octalFlipFlop1;
    invert *invert0,*invert1,*invert2,*invert3,*invert4,*invert5;
    flipFlop *flipFlop0,*flipFlop1;
    modRateCountProm *modRateCountProm0;
    modRateCount *modRateCount0;
    /*
    byteSplitter *split0;
    byteSplitter *split1;
    dacSlotAddrCount *count0;
    
    
    flipFlop *flipFlop1;
    flipFlop *flipFlop2;
    modCount *modCount0;
    invert *invert0;
    invert *invert1;
    invert *invert2;
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
    dram *dram0;
    */


    // declare signals
    sc_clock clk_sig;
    sc_signal<bool> rst_sig;
    sc_signal<sc_uint<8>> program0, decaytime0, preDelay0, program1, preDelay1, decaytime1, ratlvl;
    sc_signal<sc_uint<8>> rom0_outp_sig, rom1_outp_sig, modRateCountData;
    sc_signal<bool> nSyncClear0, DAC0, DACEN0, RAS0, CAS0, SARCK0, nS0, nMOD0;
    sc_signal<bool> nDACX0, ISH0, nER0, nEL0, nEF0, nET0, MSBE0, LSBE0;
    sc_signal<bool> nSyncClear1, DAC1, DACEN1, RAS1, CAS1, SARCK1, nS1, nMOD1;
    sc_signal<bool> nDACX1, ISH1, nER1, nEL1, nEF1, nET1, MSBE1, LSBE1;
    sc_signal<bool> nDAC, TC1, nTC1, nTCB1, DTCB1, nDDTCB1, TCB1, TCB2, TCB7, nTCB7, TCB7A;
    sc_signal<bool> SNMODEN, MODDIS;
    sc_signal<bool> carry, MCCK;
    sc_signal<sc_uint<16>> MC0_12;
    sc_signal<sc_uint<8>> TC0_7, TCB2_7, MC5_12;
    sc_signal<sc_uint<8>> nROW, nCOLUMN, writeAddrData;
    sc_signal<bool> c0, c4;
    sc_signal<sc_uint<8>> delayData0, delayData1;
    sc_signal<bool> pullHigh, pullLow;
    sc_signal<sc_uint<8>> address0, address1;
    sc_signal<sc_uint<16>> address2;
    sc_signal<sc_uint<8>> gainModCtrlData, gainModData, gainData, gain;
    sc_signal<bool> nGainModPromEnable, gainModPromEnabled, nGSN, nGainLatch, flipFlop2outp, nSelectA, compOutp0;
    sc_signal<bool> debug0, nc0, nc1, nc2, nc3,nc4,nc5; //not connected

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
        tb0->outp4(delayData1);
        tb0->outp5(nROW);
        tb0->outp6(nCOLUMN);
        tb0->outp7(writeAddrData);
        tb0->outp8(address0);
        tb0->outp9(address1);
        tb0->outp16(address2);
        tb0->outp20(nSyncClear1);
        tb0->outp21(DAC1);
        tb0->outp22(DACEN1);
        tb0->outp23(CAS1);
        tb0->outp24(RAS1);
        tb0->outp25(SARCK1);
        tb0->outp26(nS1);
        tb0->outp27(nMOD1);
        tb0->outp28(nDACX1);
        tb0->outp29(ISH1);
        tb0->outp30(nER1);
        tb0->outp31(nEL1);
        tb0->outp32(nEF1);
        tb0->outp33(nET1);
        tb0->outp34(MSBE1);
        tb0->outp35(LSBE1);
        tb0->outp36(nDAC);
        tb0->outp37(nTCB1);
        tb0->outp38(TCB7);
        tb0->outp39(debug0);

        controlLogic0 = new controlLogic("controlLogic0");
        controlLogic0->programInp(program0);
        controlLogic0->predelayInp(preDelay0);
        controlLogic0->decaytimeInp(decaytime0);
        controlLogic0->programOutp(program1);
        controlLogic0->predelayOutp(preDelay1);
        controlLogic0->decaytimeOutp(decaytime1);

        tim0 = new timer0("LS163_0");
        tim0->clk(clk_sig);
        tim0->clr(pullHigh);
        tim0->outp0(TC0_7);
        tim0->outp1(TC1);
        tim0->outp5(nc0);

        invert0 = new invert("inv_0");
        invert0->inp0(TC1);
        invert0->outp0(nTC1);

        flipFlop0 = new flipFlop("LS374_2");
        flipFlop0->clk(clk_sig);
        flipFlop0->clr(pullHigh);
        flipFlop0->inp0(nTC1);
        flipFlop0->outp0(nTCB1);
        flipFlop0->outp1(nc1);

        timingProms0 = new timingProms("28L22_0");
        timingProms0->inp0(TC0_7);
        timingProms0->outp0(nSyncClear0);
        timingProms0->outp1(DAC0);
        timingProms0->outp2(DACEN0);
        timingProms0->outp3(CAS0);
        timingProms0->outp4(RAS0);
        timingProms0->outp5(SARCK0);
        timingProms0->outp6(nS0);
        timingProms0->outp7(nMOD0);
        timingProms0->outp8(nDACX0);
        timingProms0->outp9(ISH0);
        timingProms0->outp10(nER0);
        timingProms0->outp11(nEL0);
        timingProms0->outp12(nEF0);
        timingProms0->outp13(nET0);
        timingProms0->outp14(MSBE0);
        timingProms0->outp15(LSBE0);

        octalFlipFlop0 = new octalFlipFlop("LS374_0");
        octalFlipFlop0->clk(clk_sig);
        octalFlipFlop0->inp0(nSyncClear0);
        octalFlipFlop0->inp1(DAC0);
        octalFlipFlop0->inp2(DACEN0);
        octalFlipFlop0->inp3(CAS0);
        octalFlipFlop0->inp4(RAS0);
        octalFlipFlop0->inp5(SARCK0);
        octalFlipFlop0->inp6(nS0);
        octalFlipFlop0->inp7(nMOD0);
        octalFlipFlop0->outp0(nSyncClear1);
        octalFlipFlop0->outp1(DAC1);
        octalFlipFlop0->outp2(DACEN1);
        octalFlipFlop0->outp3(CAS1);
        octalFlipFlop0->outp4(RAS1);
        octalFlipFlop0->outp5(SARCK1);
        octalFlipFlop0->outp6(nS1);
        octalFlipFlop0->outp7(nMOD1);

        octalFlipFlop1 = new octalFlipFlop("LS374_1");
        octalFlipFlop1->clk(clk_sig);
        octalFlipFlop1->inp0(nDACX0);
        octalFlipFlop1->inp1(ISH0);
        octalFlipFlop1->inp2(nER0);
        octalFlipFlop1->inp3(nEL0);
        octalFlipFlop1->inp4(nEF0);
        octalFlipFlop1->inp5(nET0);
        octalFlipFlop1->inp6(MSBE0);
        octalFlipFlop1->inp7(LSBE0);
        octalFlipFlop1->outp0(nDACX1);
        octalFlipFlop1->outp1(ISH1);
        octalFlipFlop1->outp2(nER1);
        octalFlipFlop1->outp3(nEL1);
        octalFlipFlop1->outp4(nEF1);
        octalFlipFlop1->outp5(nET1);
        octalFlipFlop1->outp6(MSBE1);
        octalFlipFlop1->outp7(LSBE1);

        invert1 = new invert("inv_1");
        invert1->inp0(DAC1);
        invert1->outp0(nDAC);

        invert2 = new invert("inv_2");
        invert2->inp0(nTCB1);
        invert2->outp0(DTCB1);

        invert3 = new invert("inv_3");
        invert3->inp0(DTCB1);
        invert3->outp0(nDDTCB1);

        tim1 = new timer1("LS163_1");
        tim1->clk(nDDTCB1);
        tim1->clr(nSyncClear1);
        tim1->outp0(TCB2_7);
        tim1->outp1(nc2);
        tim1->outp5(TCB7);

        invert4 = new invert("inv_4");
        invert4->inp0(DTCB1);
        invert4->outp0(nDDTCB1);
/*
        flipFlop0 = new flipFlop("LS374_0");
        flipFlop0->clk(clk_sig);
        flipFlop0->inp0(rom0_outp_sig);

        count0 = new dacSlotAddrCount("count0");
        count0->clk(nDDTCB1);
        count0->clr(nSyncClear);
        count0->outp0(TCB2_7);
        count0->outp1(TCB7);
        count0->outp2(TCB2);
        count0->outp3(TCB7A);
        count0->outp4(nTCB7);
        
        delayProms0 = new delayProms("delayProms0");
        delayProms0->chipEnable(nMOD);
        delayProms0->address0(TCB2_7);
        delayProms0->address1(MC5_12);
        delayProms0->address2(preDelay1);
        delayProms0->address3(program1);
        delayProms0->outp0(delayData0);

        byteReg0 = new byteReg("byteReg0");
        byteReg0->clk(nTCB1);
        byteReg0->inp0(delayData0);
        byteReg0->outp0(delayData1);

        writeAddrCount0 = new writeAddrCount("writeAddrCount0");
        writeAddrCount0->clk(TCB7A);
        writeAddrCount0->outp0(nROW);
        writeAddrCount0->outp1(nCOLUMN);

        byteInvertMux0 = new byteInvertMux("byteInvertMux0");
        byteInvertMux0->sel(TCB2);
        byteInvertMux0->inp0(nROW);
        byteInvertMux0->inp1(nCOLUMN);
        byteInvertMux0->outp0(writeAddrData);

        byteFullAdder0 = new byteFullAdder("byteFullAdder0");
        byteFullAdder0->inp0(writeAddrData);
        byteFullAdder0->inp1(delayData1);
        byteFullAdder0->cIn(c0);
        byteFullAdder0->outp0(address0);
        byteFullAdder0->cOut(c4);

        flipFlop1 = new flipFlop("flipFlop1");
        flipFlop1->clk(nTCB1);
        flipFlop1->clr(RAS);
        flipFlop1->inp0(c4);
        flipFlop1->outp0(c0);

        addressMangle0 = new addressMangle("addressMangle0");
        addressMangle0->inp0(address0);
        addressMangle0->outp0(address1);

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
        flipFlop0 = new flipFlop("flipFlop0");
        flipFlop0->clk(nTCB7);
        flipFlop0->clr(pullHigh);
        flipFlop0->inp0(carry);
        flipFlop0->outp0(MCCK);

        dram0 = new dram("dram0");
        dram0->ras(RAS);
        dram0->cas(CAS);
        dram0->inp0(address1);
        dram0->outp0(address2);

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

        flipFlop2 = new flipFlop("flipFlop2");
        flipFlop2->clk(TCB1);
        flipFlop2->clr(pullHigh);
        flipFlop2->inp0(TCB2);
        flipFlop2->outp0(flipFlop2outp);

        bitNAND1 = new bitNAND("bitNAND1");
        bitNAND1->inp0(nTCB1);
        bitNAND1->inp1(flipFlop2outp);
        bitNAND1->outp0(nGainLatch);

        latchedMux0 = new latchedMux("latchedMux0");
        latchedMux0->clk(nGainLatch);
        latchedMux0->sel(nSelectA);
        latchedMux0->inp0(gainModData);
        latchedMux0->inp1(gainData);
        latchedMux0->outp0(gain);
        */
    }
    ~SYSTEM() // destructor
    {
        // free up allocated memory space when the simulation ends
        delete tb0;
        delete tim0;
        delete timingProms0;
        delete controlLogic0;
        delete octalFlipFlop0;
        delete octalFlipFlop1;
        delete invert0;
        delete invert1;
        delete invert2;
        delete invert3;
        delete invert4;
        delete invert5;
        delete flipFlop0;
        delete flipFlop1;
        delete modRateCountProm0;
        delete modRateCount0;
        /*
        delete count0;
        delete split0;
        delete split1;
        
        
        delete flipFlop1;
        delete modCount0;
        
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
        delete dram0;
        */
    }
};

SYSTEM *top = NULL; // declare instance pointer called "top" and send that pointer to NULL

int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    top = new SYSTEM("top");
    sc_start(); // start simulation
    return 0;
};