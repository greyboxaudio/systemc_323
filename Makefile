main: main.cpp tb.cpp timer0.cpp timingProms.cpp
	gcc -o main main.cpp tb.cpp timer0.cpp timingProms.cpp -I . -I /opt/systemc/include -L /opt/systemc/lib -lsystemc -lstdc++ -lm