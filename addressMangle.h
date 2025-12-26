#include <systemc.h>
SC_MODULE(addressMangle)
{
    sc_in<sc_uint<8>> inp0;
    sc_out<sc_uint<8>> outp0;

    void addressMangle_main(){
        sc_uint<8> data = inp0.read();
        outp0.write(data[6]+((data & 63)<< 1) + (data[7] << 7));
    }

    SC_CTOR(addressMangle)
    {
        SC_METHOD(addressMangle_main);
        sensitive << inp0;
    }
};