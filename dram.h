#include <systemc.h>
SC_MODULE(dram)
{
    sc_in<bool> ras;
    sc_in<bool> cas;
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<16>> outp0;
    sc_uint<8> row_addr;
    sc_uint<8> col_addr;

    void row_reg(){
        row_addr = inp0.read();
    }
    void col_reg(){
        col_addr = inp0.read();
        outp0.write(row_addr + (col_addr << 8));
    }

    SC_CTOR(dram)
    {
        SC_METHOD(row_reg);
        sensitive << ras.neg();
        SC_METHOD(col_reg);
        sensitive << cas.neg();
    }
};