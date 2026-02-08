#include "gainProm.h"
#include "eproms.h"
void gainProm::gainProm_main(void)
{
    sc_uint<16> address = inp0.read() + ((inp1.read() & 0x7) << 5) + (inp2.read() << 8) + ((inp0.read() & 0x8) << 12);
    sc_uint<8> data;
    bool enable = ce.read();

    if (!enable)
    {
        data = d0806_626[address];
    }
    outp0.write(data & 0x7f);
    outp1.write(data[7]);
}