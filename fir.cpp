#include "fir.h"

//Coefficients for each FIR
const sc_uint<8> coefs[5] = {
    18,
    77,
    107,
    77,
    18
};

//FIR Main thread
//scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void fir::fir_main(void)
{
    sc_int<16> taps[5]; //array for input values

    //reset code
    for (int i = 0; i < 5; i++)
    {
        taps[i] = 0;
    }
    inp_rdy.write(0);
    outp_vld.write(0);
    outp.write(0);
    wait();

    while(true){
        sc_int<16> in_val;
        sc_int<16> out_val;
        //handshake
        inp_rdy.write(1);
        do
        {
            wait();
        } while (!inp_vld.read());
        
        in_val = inp.read();//read input
        inp_rdy.write(0);

        //shift previous input values
        for (int i = 5-1; i > 0; i--)
        {
            taps[i] = taps[i-1];
        }
        taps[0]=in_val;
        for (int i = 0; i < 5; i++) //multiply & accumulate
        {
            out_val += coefs[i] * taps[i];
        }
        //handshake
        outp_vld.write(1);
        outp.write(out_val);//write output
        do
        {
            wait();
        } while (!outp_rdy.read());
        outp_vld.write(0);
    }
}