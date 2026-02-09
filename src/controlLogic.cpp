#include "controlLogic.h"
    void controlLogic::controlLogic_pgm(void)
    {
        // read input as gray code binary
        sc_uint<4> index = programInp.read();
        sc_uint<4> num = grayCode[index];
        // xor bit3 with bit4
        num[2] = num[2] ^ num[3];
        programOutp.write(num);
    }
    void controlLogic::controlLogic_pdly(void)
    {
        // read input as gray code binary
        sc_uint<4> index = predelayInp.read();
        sc_uint<4> num = grayCode[index];
        predelayOutp.write(num);
    }

    void controlLogic::controlLogic_decay(void)
    {
        // read input as gray code binary
        sc_uint<4> index = decaytimeInp.read();
        sc_uint<4> num = grayCode[index];
        // xor bit3 with bit4
        num[2] = num[2] ^ num[3];
        decaytimeOutp.write(num);
    }