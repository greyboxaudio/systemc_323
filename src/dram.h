#include <systemc.h>
SC_MODULE(dram)
{
    sc_in<bool> ras,cas;
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<16>> outp0;

    sc_uint<8> row_addr;
    sc_uint<8> col_addr;

    void dram_strobeRow();
    void dram_strobeCol();

    SC_CTOR(dram)
    {
        SC_METHOD(dram_strobeRow);
        sensitive << ras.pos();
        SC_METHOD(dram_strobeCol);
        sensitive << cas.pos();
    }
};