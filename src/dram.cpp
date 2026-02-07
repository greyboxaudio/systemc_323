#include "dram.h"

    void dram::row_reg(void){
        row_addr = inp0.read();
    }
    void dram::col_reg(void){
        col_addr = inp0.read();
        outp0.write(row_addr + (col_addr << 8));
    }