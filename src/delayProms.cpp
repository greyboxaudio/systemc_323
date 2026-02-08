#include "delayProms.h"
#include "eproms.h"

void delayProms::dlyData(void)
{
    sc_uint<16> address;
    sc_uint<8> data;
    bool enable0 = ce0.read();
    bool enable1 = ce1.read();
    if (!enable1)
    {
        address = inp2.read() + ((inp3.read() & 0x7) << 6) + ((inp4.read() & 0x07) << 9) + ((inp3.read() & 0x08) << 12) + ((inp4.read() & 0x08) << 13);
        data = d0808_626[address];
        outp0.write(data);
        outp1.write(address);
    }
    if (!enable0)
    {
        address = inp0.read() + (inp1.read() << 5);
        data = d0807[address];
        outp0.write(data);
        outp1.write(address);
    }
}