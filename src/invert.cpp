#include "invert.h"

void invert::invert_main(void)
{
    bool a = inp0.read();
    outp0.write(!a);
}