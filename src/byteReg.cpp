#include "byteReg.h"
    void byteReg::latch(void){
        sc_uint<8> data = inp0.read();
        outp0.write(data);
    }