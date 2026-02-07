#include "octalFlipFlop.h"
    void octalFlipFlop::func(void){
        outp0.write(inp0.read());
        outp1.write(inp1.read());
        outp2.write(inp2.read());
        outp3.write(inp3.read());
        outp4.write(inp4.read());
        outp5.write(inp5.read());
        outp6.write(inp6.read());
        outp7.write(inp7.read());
    }