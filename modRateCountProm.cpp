#include "modRateCountProm.h"
#include "eproms.h"
void modRateCountProm::func(void)
{
    sc_uint<8> promAddress = address0.read() + (address1.read() << 4);
    sc_uint<8> promData = d0803_626[promAddress];
    //sc_uint<8> promData = d0803[promAddress];
    outp0.write(promData);
    outp1.write(promData[5]);
    outp2.write(promData[6]);
}