#!/bin/bash
gcc -o sg323_main sg323_main.cpp tb323.cpp sg323.cpp -I . -I /opt/systemc/include -L /opt/systemc/lib -lsystemc -lstdc++ -lm
./sg323_main
