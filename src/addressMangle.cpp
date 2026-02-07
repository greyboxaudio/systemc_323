#include "addressMangle.h"

    void addressMangle::addressMangle_main(void){
        sc_uint<8> data = inp0.read();
        outp0.write(data[6] + ((data & 0x3f)<< 1) + (data[7] << 7));
    }
