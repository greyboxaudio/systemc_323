#include "timingProms.h"
#include "eproms.h"
void timingProms::start_of_simulation( void )
{
    bool value = 0;
        outp0.write(value);
        outp1.write(value);
        outp2.write(value);
        outp3.write(value);
        outp4.write(value);
        outp5.write(value);
        outp6.write(value);
        outp7.write(value);
        outp8.write(value);
        outp9.write(value);
        outp10.write(value);
        outp11.write(value);
        outp12.write(value);
        outp13.write(value);
        outp14.write(value);
        outp15.write(value);
}
void timingProms::func(void)
{
        sc_uint<8> address = inp0.read();
        sc_uint<8> data0 = d0810[address];
        sc_uint<8> data1 = d0811[address];
        outp0.write(data0[0].to_bool());
        outp1.write(data0[1].to_bool());
        outp2.write(data0[2].to_bool());
        outp3.write(data0[3].to_bool());
        outp4.write(data0[4].to_bool());
        outp5.write(data0[5].to_bool());
        outp6.write(data0[6].to_bool());
        outp7.write(data0[7].to_bool());
        outp8.write(data1[0].to_bool());
        outp9.write(data1[1].to_bool());
        outp10.write(data1[2].to_bool());
        outp11.write(data1[3].to_bool());
        outp12.write(data1[4].to_bool());
        outp13.write(data1[5].to_bool());
        outp14.write(data1[6].to_bool());
        outp15.write(data1[7].to_bool());
}