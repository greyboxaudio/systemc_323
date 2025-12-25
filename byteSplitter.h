#include <systemc.h>
SC_MODULE(byteSplitter)
{
    sc_in<sc_uint<8>> inp0;
    sc_out<bool> outp0;
    sc_out<bool> outp1;
    sc_out<bool> outp2;
    sc_out<bool> outp3;
    sc_out<bool> outp4;
    sc_out<bool> outp5;
    sc_out<bool> outp6;
    sc_out<bool> outp7;

    void byteSplitter_main()
    {
        outp0.write(inp0.read()[0]);
        outp1.write(inp0.read()[1]);
        outp2.write(inp0.read()[2]);
        outp3.write(inp0.read()[3]);
        outp4.write(inp0.read()[4]);
        outp5.write(inp0.read()[5]);
        outp6.write(inp0.read()[6]);
        outp7.write(inp0.read()[7]);
    }

    SC_CTOR(byteSplitter)
    {
        SC_METHOD(byteSplitter_main);
        sensitive << inp0;
    }
};