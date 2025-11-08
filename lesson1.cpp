#include <systemc.h>
//define module
SC_MODULE(and2){
    sc_in< sc_uint<1> > a, b;
    sc_in<bool> clk;
    sc_out< sc_uint<1> > f;

    //write function to execute the module function
    void func()
    {
        f.write(a.read() & b.read() );
    }

    //constructor must have the same name as the module. runs once when the module is instantiated in the simulation
    SC_CTOR(and2)
    {
        //define Thread. A thread is a function made to act like a hardware process
        SC_METHOD (func); //SC_METHOD executes once every sensitivity event. Runs continuously. Executes in one cycle.
        //enable clock on positive edge
        sensitive << clk.pos();
    }
};