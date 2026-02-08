#include <systemc.h>
#include "addressMangle.h"
#include "byteFullAdder.h"
#include "byteInvertMux.h"
#include "byteReg.h"
#include "comparator.h"
#include "controlLogic.h"
#include "delayProms.h"
#include "dram.h"
#include "flipFlop.h"
#include "gainModCtrlProm.h"
#include "gainModProm.h"
#include "gainProm.h"
#include "invert.h"
#include "latchedMux.h"
#include "modRateCountProm.h"
#include "nand.h"
#include "octalFlipFlop.h"
#include "timer0.h"
#include "timer1.h"
#include "timer2.h"
#include "timer3.h"
#include "timer4.h"
#include "timingProms.h"


int sc_main(int argc, char *argv[]) // declare systemc main function as int, so that it can return something.
{
    controlLogic *controlLogic0;
    timer0 *tim0;
    timer1 *tim1;
    timer2 *tim2;
    timer3 *tim3;
    timer4 *tim4;
    timingProms *timingProms0;
    octalFlipFlop *octalFlipFlop0, *octalFlipFlop1;
    invert *invert0, *invert1, *invert2, *invert3, *invert4, *invert5, *invert6, *invert7;
    invert *invert8, *invert9;
    nand *nand0,*nand1,*nand2,*nand3;
    flipFlop *flipFlop0, *flipFlop1, *flipFlop2, *flipFlop3, *flipFlop4;
    modRateCountProm *modRateCountProm0;
    delayProms *delayProms0;
    byteReg *byteReg0;
    byteInvertMux *byteInvertMux0;
    byteFullAdder *byteFullAdder0;
    addressMangle *addressMangle0;
    dram *dram0;
    gainModCtrlProm *gainModCtrlProm0;
    gainModProm *gainModProm0;
    gainProm *gainProm0;
    latchedMux *latchedMux0;
    comparator *comparator0;

    sc_clock clk_sig("clk_sig", 122, SC_NS);
    sc_signal<bool> rst_sig;
    sc_signal<sc_uint<4>> program0, decaytime0, preDelay0, program1, preDelay1, decaytime1, ratlvl;
    sc_signal<sc_uint<8>> rom0_outp_sig, rom1_outp_sig, modRateCountData;
    sc_signal<bool> nSyncClear0, DAC0, DACEN0, RAS0, CAS0, SARCK0, nS0, nMOD0;
    sc_signal<bool> nDACX0, ISH0, nER0, nEL0, nEF0, nET0, MSBE0, LSBE0;
    sc_signal<bool> nSyncClear1, DAC1, DACEN1, RAS1, CAS1, SARCK1, nS1, nMOD1;
    sc_signal<bool> nDACX1, ISH1, nER1, nEL1, nEF1, nET1, MSBE1, LSBE1;
    sc_signal<bool> nDAC, TC1, nTC1, nTCB1, DTCB1, nDDTCB1, TCB1, TCB2, TCB7, nTCB7, TCB7A;
    sc_signal<bool> SNMODEN, MODDIS, MOD, nMODB;
    sc_signal<bool> MCCK, nMCCK;
    sc_signal<sc_uint<16>> MC0_8;
    sc_signal<sc_uint<8>> TC0_7, TCB2_7, TCB3_7, MC6_12;
    sc_signal<sc_uint<8>> nROW, nCOLUMN, writeAddrData;
    sc_signal<bool> modCarry, nModCarry, rowCarryIn, rowCarryOut;
    sc_signal<sc_uint<8>> delayData0, delayData1;
    sc_signal<bool> pullHigh, pullLow;
    sc_signal<sc_uint<8>> address0, address1;
    sc_signal<sc_uint<16>> address2, dlyaddr0;
    sc_signal<sc_uint<8>> gainModCtrlData, gainModData, gainData, gain;
    sc_signal<bool> nGainModPromEnable, gainModPromEnabled, nGSN, nGainLatch, gainFlipFlopOut, nSelectA, compOutp;
    sc_signal<bool> debug0, nc0, nc1, nc2, nc3, nc4, nc5;

    program0 = 15;
    preDelay0 = 8;
    decaytime0 = 15;
    ratlvl = 0;
    pullHigh = 1;
    pullLow = 0;

    controlLogic0 = new controlLogic("controlLogic0");
    controlLogic0->programInp(program0);
    controlLogic0->predelayInp(preDelay0);
    controlLogic0->decaytimeInp(decaytime0);
    controlLogic0->programOutp(program1);
    controlLogic0->predelayOutp(preDelay1);
    controlLogic0->decaytimeOutp(decaytime1);

    tim0 = new timer0("timingCounter");
    tim0->clk(clk_sig);
    tim0->outp0(TC0_7);
    tim0->outp1(TC1);

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

    invert1 = new invert("inv_DAC");
    invert1->inp0(DAC1);
    invert1->outp0(nDAC);

    invert2 = new invert("inv_nTCB1");
    invert2->inp0(nTCB1);
    invert2->outp0(DTCB1);

    invert3 = new invert("inv_DTCB1");
    invert3->inp0(DTCB1);
    invert3->outp0(nDDTCB1);

    tim1 = new timer1("dacSlotAddressCounter");
    tim1->clk(nTCB1);
    tim1->clr(nSyncClear1);
    tim1->outp0(TCB2_7);
    tim1->outp1(TCB3_7);
    tim1->outp2(TCB2);  
    tim1->outp3(TCB7);

    modRateCountProm0 = new modRateCountProm("modRateCountProm");
    modRateCountProm0->inp0(ratlvl);
    modRateCountProm0->inp1(program1);
    modRateCountProm0->outp0(modRateCountData);

    tim2 = new timer2("modRateCounter");
    tim2->clk(TCB7);
    tim2->ld(nModCarry);
    tim2->inp0(modRateCountData);
    tim2->outp0(modCarry);

    invert4 = new invert("inv_modCarry");
    invert4->inp0(modCarry);
    invert4->outp0(nModCarry);

    invert5 = new invert("inv_TCB7");
    invert5->inp0(TCB7);
    invert5->outp0(nTCB7);

    flipFlop2 = new flipFlop("MCCK_Latch");
    flipFlop2->clk(nTCB7);
    flipFlop2->clr(pullHigh);
    flipFlop2->inp0(modCarry);
    flipFlop2->outp0(MCCK);
    flipFlop2->outp1(nc3);

    invert6 = new invert("inv_MCCK");
    invert6->inp0(MCCK);
    invert6->outp0(nMCCK);

    tim3 = new timer3("modCounter");
    tim3->clk(nMCCK);
    tim3->outp0(MC0_8);
    tim3->outp1(MC6_12);

    gainModCtrlProm0 = new gainModCtrlProm("gainModCtrlProm");
    gainModCtrlProm0->ce(nDAC);
    gainModCtrlProm0->inp0(TCB3_7);
    gainModCtrlProm0->inp1(MC6_12);
    gainModCtrlProm0->outp0(gainModCtrlData);
    gainModCtrlProm0->outp1(nGainModPromEnable);

    gainModProm0 = new gainModProm("gainModProm");
    gainModProm0->ce(nGainModPromEnable);
    gainModProm0->inp0(gainModCtrlData);
    gainModProm0->inp1(MC0_8);
    gainModProm0->outp0(gainModData);

    gainProm0 = new gainProm("gainProm");
    gainProm0->ce(nDACX1);
    gainProm0->inp0(TCB3_7);
    gainProm0->inp1(decaytime1);
    gainProm0->inp2(program1);
    gainProm0->outp0(gainData);
    gainProm0->outp1(nGSN);

    nand0 = new nand("nand0");
    nand0->inp0(nGainModPromEnable);
    nand0->inp1(pullHigh);
    nand0->outp0(gainModPromEnabled);

    nand1 = new nand("nand1");
    nand1->inp0(gainModPromEnabled);
    nand1->inp1(compOutp);
    nand1->outp0(nSelectA);

    nand2 = new nand("nand2");
    nand2->inp0(nTCB1);
    nand2->inp1(nTCB1);
    nand2->outp0(TCB1);

    nand3 = new nand("nand3");
    nand3->inp0(nTCB1);
    nand3->inp1(gainFlipFlopOut);
    nand3->outp0(nGainLatch);

    flipFlop4 = new flipFlop("flipFlop4");
    flipFlop4->clk(TCB1);
    flipFlop4->clr(pullHigh);
    flipFlop4->inp0(TCB2);
    flipFlop4->outp0(gainFlipFlopOut);
    flipFlop4->outp1(nc5);

    latchedMux0 = new latchedMux("latchedMux");
    latchedMux0->clk(nGainLatch);
    latchedMux0->sel(nSelectA);
    latchedMux0->inp0(gainModData);
    latchedMux0->inp1(gainData);
    latchedMux0->outp0(gain);

    comparator0 = new comparator("gainComparator");
    comparator0->inp0(gainModData);
    comparator0->inp1(gainData);
    comparator0->outp0(compOutp);

    invert9 = new invert("inv_nTCB7");
    invert9->inp0(nTCB7);
    invert9->outp0(TCB7A);

    tim4 = new timer4("writeAddrCounter");
    tim4->clk(TCB7);
    tim4->outp0(nROW);
    tim4->outp1(nCOLUMN);

    byteInvertMux0 = new byteInvertMux("rowColumnMux");
    byteInvertMux0->sel(TCB2);
    byteInvertMux0->inp0(nROW);
    byteInvertMux0->inp1(nCOLUMN);
    byteInvertMux0->outp0(writeAddrData);

    invert7 = new invert("inv_nMOD");
    invert7->inp0(nMOD1);
    invert7->outp0(MOD);

    invert8 = new invert("inv_MOD");
    invert8->inp0(MOD);
    invert8->outp0(nMODB);

    delayProms0 = new delayProms("delayProms0");
    delayProms0->ce0(nMODB);
    delayProms0->ce1(MOD);
    delayProms0->inp0(TCB3_7);
    delayProms0->inp1(MC6_12);
    delayProms0->inp2(TCB2_7);
    delayProms0->inp3(preDelay1);
    delayProms0->inp4(program1);
    delayProms0->outp0(delayData0);
    delayProms0->outp1(dlyaddr0);

    byteReg0 = new byteReg("delayDataReg");
    byteReg0->clk(nTCB1);
    byteReg0->inp0(delayData0);
    byteReg0->outp0(delayData1);

    byteFullAdder0 = new byteFullAdder("delayAdder");
    byteFullAdder0->inp0(writeAddrData);
    byteFullAdder0->inp1(delayData1);
    byteFullAdder0->c0(rowCarryIn);
    byteFullAdder0->outp0(address0);
    byteFullAdder0->c4(rowCarryOut);

    flipFlop3 = new flipFlop("rowCarryOutLatch");
    flipFlop3->clk(nTCB1);
    flipFlop3->clr(RAS1);
    flipFlop3->inp0(rowCarryOut);
    flipFlop3->outp0(rowCarryIn);
    flipFlop3->outp1(nc4);

    addressMangle0 = new addressMangle("addressMangle0");
    addressMangle0->inp0(address0);
    addressMangle0->outp0(address1);

    dram0 = new dram("dramArray");
    dram0->ras(RAS1);
    dram0->cas(CAS1);
    dram0->inp0(address1);
    dram0->outp0(address2);

    sc_trace_file *file = sc_create_vcd_trace_file("trace");
    sc_trace(file, clk_sig, "sysclk");
    sc_trace(file, TC0_7, "TC0_7");
    sc_trace(file, TCB2_7, "TCB2_7");
    sc_trace(file, TCB3_7, "TCB3_7");
    sc_trace(file, nTCB1, "nTCB1");
    sc_trace(file, nDDTCB1, "nDDTCB1");
    sc_trace(file, TCB2, "TCB2");
    sc_trace(file, TCB7, "TCB7");
    sc_trace(file, TCB7, "nTCB7");
    sc_trace(file, TCB7A, "TCB7A");
    sc_trace(file, nS1, "nS");
    sc_trace(file, SARCK1, "SARCK");
    sc_trace(file, RAS1, "RAS");
    sc_trace(file, CAS1, "CAS");
    sc_trace(file, DACEN1, "DACEN");
    sc_trace(file, LSBE1, "LSBE");
    sc_trace(file, MSBE1, "MSBE");
    sc_trace(file, DAC1, "DAC");
    sc_trace(file, nMOD1, "nMOD");
    sc_trace(file, nSyncClear1, "nSYNCCLEAR");
    sc_trace(file, nDACX1, "nDACX");
    sc_trace(file, delayData0, "delayData0");
    sc_trace(file, delayData1, "delayData1");
    sc_trace(file, nROW, "nROW");
    sc_trace(file, nCOLUMN, "nCOLUMN");
    sc_trace(file, writeAddrData, "writeAddressData");
    sc_trace(file, address0, "address0");
    sc_trace(file, address1, "address1");
    sc_trace(file, address2, "address2");
    sc_trace(file, rowCarryIn, "rowCarryIn");
    sc_trace(file, rowCarryOut, "rowCarryOut");
    sc_trace(file, dlyaddr0, "dlyAddress");
    sc_trace(file, MC0_8, "MC0_8");
    sc_trace(file, MC6_12, "MC6_12");
    sc_trace(file, nGainModPromEnable, "nGainModPromEnable");
    sc_trace(file, nGSN, "nGSN");
    sc_trace(file, gainModCtrlData, "gainModCtrlData");
    sc_trace(file, gainModData, "gainModData");
    sc_trace(file, gainData, "gainData");
    sc_trace(file, nGainLatch, "nGainLatch");
    sc_trace(file, nSelectA, "nSelectA");
    sc_trace(file, gain, "gain");
    sc_trace(file, compOutp, "A<B");
    sc_trace(file, gainFlipFlopOut, "gainFlipFlopOut");
    sc_trace(file, TCB1, "TCB1");
    sc_trace(file, nDAC, "nDAC");
    //sc_trace(file, , "");
    
    sc_start(100, SC_US); // start simulation
    sc_close_vcd_trace_file(file);

    delete tim0, tim1, tim2, tim3, tim4;
    delete timingProms0;
    delete controlLogic0;
    delete octalFlipFlop0, octalFlipFlop1;
    delete invert0, invert1, invert2, invert3;
    delete invert4, invert5, invert6, invert7;
    delete invert8, invert9;
    delete nand0,nand1,nand2,nand3;
    delete flipFlop0, flipFlop1, flipFlop2, flipFlop3,flipFlop4;
    delete modRateCountProm0;
    delete delayProms0;
    delete byteReg0;
    delete byteInvertMux0;
    delete byteFullAdder0;
    delete addressMangle0;
    delete dram0;
    delete gainModCtrlProm0;
    delete gainModProm0;
    delete gainProm0;
    delete latchedMux0;
    delete comparator0;

    return 0;
};