#include "dram.h"

    void dram::dram_strobeRow(void){
        row_addr = inp0.read();
    }
    void dram::dram_strobeCol(void){
        col_addr = inp0.read();
        outp0.write(row_addr + (col_addr << 8));
    }