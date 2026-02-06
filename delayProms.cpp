#include "delayProms.h"
#include "eproms.h"

void delayProms::dlyData(void)
{
    sc_uint<16> address = inp2.read() + ((inp3.read() & 0x07) << 6) + ((inp4.read() & 0x07) << 9) + ((inp3.read() & 0x08) << 12) + ((inp4.read() & 0x08) << 13);
    sc_uint<8> data = d0808_626[address];
    outp0.write(data);
}
void delayProms::modData(void)
{
    sc_uint<16> address = inp0.read() + (inp1.read() << 5);
    sc_uint<8> data = d0807[address];
    outp1.write(data);
}