#include <systemc.h>
#include "tb.h"
#include "sg323.h"

SC_MODULE(SYSTEM)
{
    //modules
    tb *tb0;
    sg323 *sg0;

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
    sc_signal<bool> pullHigh, pullLow;
    sc_signal<sc_uint<8>> address0, address1;
    sc_signal<sc_uint<16>> address2;
    sc_signal<sc_uint<8>> gainModCtrlData, gainModData, gainData, gain;
    sc_signal<bool> nGainModPromEnable, gainModPromEnabled, nGSN, nGainLatch, bitFlipFlop2outp, nSelectA, compOutp0;
    sc_signal<bool> debug0;
    
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
        tb0->outp39(debug0);

        sg0 = new sg323("sg323");
        sg0->clk(clk_sig);
        sg0->rst(rst_sig);
        sg0->inp0(program0);
        sg0->inp1(preDelay0);
        sg0->inp2(decaytime0);
        sg0->outp0(address2);
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