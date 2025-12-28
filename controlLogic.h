#include <systemc.h>
SC_MODULE(controlLogic)
{
    sc_in<sc_uint<8>> programInp, predelayInp, decaytimeInp;
    sc_out<sc_uint<8>> programOutp, predelayOutp, decaytimeOutp;

    void program_func()
    {
        sc_uint<8> num = programInp.read();
        // convert decimal to gray code binary
        num = num ^ (num >> 1);
        // xor bit3 with bit4
        num[3] = num[3] ^ num[4];
        programOutp.write(num);
    }
    void predelay_func()
    {
        sc_uint<8> num = predelayInp.read();
        // convert decimal to gray code binary
        num = num ^ (num >> 1);
        predelayOutp.write(num);
    }

    void decaytime_func()
    {
        sc_uint<8> num = decaytimeInp.read();
        // convert decimal to gray code binary
        num = num ^ (num >> 1);
        // xor bit3 with bit4
        num[3] = num[3] ^ num[4];
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