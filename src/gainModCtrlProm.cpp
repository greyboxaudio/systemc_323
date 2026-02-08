#include "gainModCtrlProm.h"
#include "eproms.h"
void gainModCtrlProm::gainModCtrlProm_main(void)
{
    sc_uint<16> address = inp0.read() + (inp1.read() << 5);
    sc_uint<8> data{};
    bool enable = ce.read();
    
    if (!enable)
    {
        data = d0804[address];
    }
    outp0.write(data & 0x7);
    outp1.write(data[3]);
}