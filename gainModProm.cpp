#include "gainModProm.h"
#include "eproms.h"
void gainModProm::gainModProm_main(void)
{
    sc_uint<16> promAddress = (address0.read() & 7) + ((address1.read() << 3) & 4088);
    sc_uint<8> promData{};
    if (chipEnable.read() == 0 && outpEnable.read() == 0)
    {
        promData = d0805[promAddress];
    }
    outp0.write(promData);
}