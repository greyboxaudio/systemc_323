#include "octalFlipFlop.h"

    void octalFlipFlop::octalFlipFlop_main(void){
        bool data0 = inp0.read();
        bool data1 = inp1.read();
        bool data2 = inp2.read();
        bool data3 = inp3.read();
        bool data4 = inp4.read();
        bool data5 = inp5.read();
        bool data6 = inp6.read();
        bool data7 = inp7.read();

        outp0.write(data0);
        outp1.write(data1);
        outp2.write(data2);
        outp3.write(data3);
        outp4.write(data4);
        outp5.write(data5);
        outp6.write(data6);
        outp7.write(data7);
    }