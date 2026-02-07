#include <systemc.h>
SC_MODULE(controlLogic)
{
    sc_in<sc_uint<4>> programInp, predelayInp, decaytimeInp;
    sc_out<sc_uint<4>> programOutp, predelayOutp, decaytimeOutp;
    sc_uint<4> grayCode[16]{15,14,12,13,9,8,10,11,3,2,0,1,5,4,6,7};

    void program_func();
    void predelay_func();
    void decaytime_func();
    
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