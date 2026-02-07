#include "gainProm.h"
#include "eproms.h"
void gainProm::gainProm_main(void)
{
    sc_uint<16> promAddress = (address0.read() >> 1) + ((address1.read() << 5) & 224) + (address2.read() << 8) + (address1.read()[3] << 12);
    sc_uint<8> promData{};
    if (chipEnable.read() == 0 && outpEnable.read() == 0)
    {
        promData = d0806_626[promAddress];
        //promData = d0806[promAddress];
    }
    outp0.write(promData);
    outp1.write(promData[7]);
}