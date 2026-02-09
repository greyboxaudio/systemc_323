#include "modRateCountProm.h"
#include "eproms.h"
void modRateCountProm::modRateCountProm_main(void)
{
    sc_uint<8> address = inp0.read() + (inp1.read() << 4);
    sc_uint<8> data = d0803_626[address] & 0xf;
    outp0.write(data);
}