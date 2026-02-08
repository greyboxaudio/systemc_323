#include "octalFlipFlop.h"

    void octalFlipFlop::func(void){
        bool data = inp0.read();
        outp0.write(data);
        data = inp1.read();
        outp1.write(data);
        data = inp2.read();
        outp2.write(data);
        data = inp3.read();
        outp3.write(data);
        data = inp4.read();
        outp4.write(data);
        data = inp5.read();
        outp5.write(data);
        data = inp6.read();
        outp6.write(data);
        data = inp7.read();
        outp7.write(data);
    }