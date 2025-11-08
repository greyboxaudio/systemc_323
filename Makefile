main: main.cpp tb.cpp fir.cpp
	gcc -o main main.cpp fir.cpp tb.cpp -I . -I /opt/systemc/include -L /opt/systemc/lib -lsystemc -lstdc++ -lm