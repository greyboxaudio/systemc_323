main: main.cpp tb.cpp fir.cpp
	gcc -o main main.cpp count8.cpp rom8.cpp rom_u46.cpp tb.cpp -I . -I /opt/systemc/include -L /opt/systemc/lib -lsystemc -lstdc++ -lm