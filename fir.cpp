#include "fir.h"

//Coefficients for each FIR
const sc_uint<8> coefs[5] = {
    18,
    77,
    107,
    77,
    18
};
sc_int<16> taps[5]; //array for input values

//FIR Main thread
//scoping module::thread; fir_main is within the scope of module fir
//(void) as argument to show explicitely that fir_main has no arguments
void fir::fir_main(void)
{
    //reset code
    //reset internal variables
    outp.write(0); //reset output
    wait(); //wait for one clock cycle

    while(true){
        //shift previous input values
        for (int i = 4; i > 0; i--)
        {
            taps[i] = taps[i-1];
        }
        taps[0]=inp.read(); //read input
        sc_int<16> val; //temporary variable to store filter accumulations
        for (int i = 0; i < 5; i++) //multiply & accumulate
        {
            val += coefs[i] * taps[i];
        }
        outp.write(val);//write output
        wait();
    }
}