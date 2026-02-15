#include "gainModProm.h"
#include "eproms.h"
void gainModProm::gainModProm_main(void)
{
    sc_uint<16> address = (inp0.read() & 0x7) + (inp1.read() << 3);
    sc_uint<8> data;
    bool enable = ce.read();

    if (!enable)
    {
        data = d0805[address];
    }
    outp0.write(data);
    outp1.write(address);
}