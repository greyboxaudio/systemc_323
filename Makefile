main: main.cpp tb.cpp fir.cpp
	gcc -o main main.cpp tb.cpp timer8.cpp latchedRom0810.cpp latchedRom0811.cpp latchTC1.cpp -I . -I /opt/systemc/include -L /opt/systemc/lib -lsystemc -lstdc++ -lm