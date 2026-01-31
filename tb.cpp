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
    for (int i = 0; i < 260; i++)
    {
        sc_uint<8> indata0 = outp0.read();
        sc_uint<8> indata1 = outp1.read();
        sc_uint<8> indata2 = outp2.read();
        sc_uint<8> indata3 = outp3.read();
        sc_uint<8> indata4 = outp4.read();
        sc_uint<8> indata5 = outp5.read();
        sc_uint<8> indata6 = outp6.read();
        sc_uint<8> indata7 = outp7.read();
        sc_uint<16> indata8 = outp8.read();
        sc_uint<16> indata9 = outp9.read();
        sc_uint<16> indata10 = outp10.read();

             cout << "dlyModAddr " << indata10.to_int()<< " | dlyAddr "<< indata9.to_int()<< " | dlyModData "<< indata0.to_int()<< " | dlyData " << indata1.to_int()<<" | nRow " << indata2.to_int()<<" | nCol " <<  indata3.to_int()<<" | dramAddr " <<  indata8.to_int()<< endl; // write loop index and value of indata to cout. .to_int() converts systemc data type to regular data type

        wait();
    }
    sc_stop(); // end simulation
}