#include "tb323.h"
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
void tb323::sink()
{
    // read values on outp port
    for (int i = 0; i < 80; i++)
    {
        sc_uint<16> address = outp0.read();
        sc_uint<8> gain = outp1.read();

             cout << i << " " << address.to_int() << " " << gain.to_int() << endl; // write loop index and value of indata to cout. .to_int() converts systemc data type to regular data type

        wait();
    }
    sc_stop(); // end simulation
}