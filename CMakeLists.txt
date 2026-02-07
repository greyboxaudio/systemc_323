cmake_minimum_required(VERSION 3.20)
project(sg323_systemc VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(/opt/systemc/include)
link_directories(/opt/systemc/lib)
add_subdirectory(src)
add_executable(main 
    src/main.cpp
    src/addressMangle.cpp
    src/byteFullAdder.cpp
    src/byteInvertMux.cpp
    src/byteReg.cpp
    src/comparator.cpp
    src/controlLogic.cpp
    src/delayProms.cpp
    src/dram.cpp
    src/flipFlop.cpp
    src/gainModCtrlProm.cpp
    src/gainModProm.cpp
    src/gainProm.cpp
    src/invert.cpp
    src/latchedMux.cpp
    src/modRateCountProm.cpp
    src/nand.cpp
    src/octalFlipFlop.cpp
    src/timer0.cpp
    src/timer1.cpp
    src/timer2.cpp
    src/timer3.cpp
    src/timer4.cpp
    src/timingProms.cpp)
target_link_libraries(main
        PUBLIC 
            systemc)