#include "invert.h"
void invert::start_of_simulation( void )
{
    bool value = 0;
    outp0.write(value);
}
void invert::invert_main(void)
{
    bool a = inp0.read();
    outp0.write(!a);
}