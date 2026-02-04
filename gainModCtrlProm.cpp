#include "gainModCtrlProm.h"
#include "eproms.h"
void gainModCtrlProm::gainModCtrlProm_main(void)
{
    sc_uint<16> promAddress = (address0.read() >> 1) + ((address1.read() << 5) & 4064);
    sc_uint<8> promData{};
    if (chipEnable.read() == 0 && outpEnable.read() == 0)
    {
        promData = d0804[promAddress];
    }
    outp0.write(promData);
    outp1.write(promData[3]);
}