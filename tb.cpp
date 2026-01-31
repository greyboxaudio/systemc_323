#include "tb.h"
/*void tb::source()
{
    // Reset
    inp.write(0);
    inp_vld.write(0);
    rst.write(1);
    wait();
    rst.write(0);
    wait();

    sc_uint<8> tmp; // temporary variable that gets sent to the fir module
    for (int i = 0; i < 64; i++)
    {
        if (i > 23 && i < 29)
        {
            tmp = 256;
        }
        else
            tmp = 0;
        // handshake
        inp_vld.write(1);
        inp.write(tmp);
        // do-while loop. continually wait until expression becomes true
        do
        {
            wait();
        } while (!inp_rdy.read());
        inp_vld.write(0);
    }
    // Guard condition for hanging simulation
    wait(10000);
    printf("Hanging simulation stopped by TB source thread");
    sc_stop();
}*/
void tb::sink()
{
    // read values on outp port
    for (int i = 0; i < 128; i++)
    {
        sc_uint<8> TC0_7 = outp0.read();
        sc_uint<8> TCB2_7 = outp1.read();
        sc_uint<8> MC5_12 = outp2.read();
        sc_uint<8> delayData0 = outp3.read();
        sc_uint<8> delayData1 = outp4.read();
        sc_uint<16> dram_addr = outp16.read(); 
        bool nSyncClear=outp20.read();
        bool DAC=outp21.read();
        bool DACEN=outp22.read();
        bool CAS=outp23.read();
        bool RAS=outp24.read();
        bool SARCK=outp25.read();
        bool nS=outp26.read();
        bool nMOD=outp27.read();
        bool nDACX=outp28.read();
        bool ISH=outp29.read();
        bool nER=outp30.read();
        bool nEL=outp31.read();
        bool nEF=outp32.read();
        bool nET=outp33.read();
        bool MSBE=outp34.read();
        bool LSBE=outp35.read();
        bool nDAC=outp36.read();
        bool nTCB1=outp37.read();
        bool TCB7=outp38.read();

             cout << i << " " << TC0_7.to_int() << " " << TCB2_7.to_int() << " " << MC5_12.to_int() << " " << delayData0.to_int() << " " << delayData1.to_int() << " " << nMOD << " " << nTCB1 << " "<< RAS << " "<< CAS << " " << dram_addr.to_int() << endl; // write loop index and value of indata to cout. .to_int() converts systemc data type to regular data type

        wait();
    }
    sc_stop(); // end simulation
}