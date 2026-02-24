#include "gainModCtrlProm.h"
#include "eproms.h"
void gainModCtrlProm::gainModCtrlProm_main(void)
{
    sc_uint<16> address = inp0.read() + (inp1.read() << 5);
    sc_uint<8> data{};
    bool enable = ce.read();
    bool outpEnable = oe.read();
    
    if (!enable)
    {
        data = d0804[address];
    }
    if (!outpEnable)
    {
        outp0.write(data & 0x7);
        outp1.write(data[3]);
    }else{
        outp0.write(0);
        outp1.write(1);
    }
    
        
}