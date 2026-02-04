#include "delayProms.h"
#include "eproms.h"
sc_uint<8> delayData;
sc_uint<16> modAddress;
sc_uint<16> dlyAddress;
void delayProms::addr_func(void)
{
    bool enable = chipEnable.read();
    modAddress = (address0.read() >> 1) + ((address1.read() & 0xfe) << 5);
    dlyAddress = address0.read() + ((address2.read() & 0x07) << 6) + ((address3.read() & 0x07) << 9) + ((address2.read() & 0x08) << 12) + ((address3.read() & 0x08) << 13);
    // delay data output
    if (enable)
    {
        delayData = d0808_626[dlyAddress];
        cout << enable << endl;
        //delayData = d0808[dlyAddress];
    }
    /*else if (chipEnable.read() == 0 && outpEnable.read() == 0)
    {
        delayData = d0807[modAddress];
    }*/
    else{
        delayData = d0807[modAddress];
        cout << enable << endl;

        //delayData = 0; // not 100% sure if this is equivalent circuit behaviour!
    }
    outp0.write(delayData);
}