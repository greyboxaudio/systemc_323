#include <systemc.h>
SC_MODULE(controlLogic)
{
    sc_in<sc_uint<4>> programInp, predelayInp, decaytimeInp;
    sc_out<sc_uint<4>> programOutp, predelayOutp, decaytimeOutp;
    sc_uint<4> grayCode[16]{15,14,12,13,9,8,10,11,3,2,0,1,5,4,6,7};

    void program_func()
    {
        // read input as gray code binary
        sc_uint<4> index = programInp.read();
        sc_uint<4> num = grayCode[index];
        // xor bit3 with bit4
        num[2] = num[2] ^ num[3];
        programOutp.write(num);
    }
    void predelay_func()
    {
        // read input as gray code binary
        sc_uint<4> index = predelayInp.read();
        sc_uint<4> num = grayCode[index];
        predelayOutp.write(num);
    }

    void decaytime_func()
    {
        // read input as gray code binary
        sc_uint<4> index = decaytimeInp.read();
        sc_uint<4> num = grayCode[index];
        // xor bit3 with bit4
        num[2] = num[2] ^ num[3];
        decaytimeOutp.write(num);
    }

    SC_CTOR(controlLogic)
    {
        SC_METHOD(program_func);
        sensitive << programInp;
        SC_METHOD(predelay_func);
        sensitive << predelayInp;
        SC_METHOD(decaytime_func);
        sensitive << decaytimeInp;
    }
};