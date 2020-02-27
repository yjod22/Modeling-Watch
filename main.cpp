#include "systemc.h"
#include "counter.h"
#include "register.h"
#include "watch.h"
int sc_main(int argc, char *argv[])  // cf. C++ main()
{
	//Declare the clock source
	sc_time period(1,SC_SEC);  //set the period of the clock
	#define duty 0.5		   //set the duty of the clock
	sc_time delay(0,SC_SEC);   //set the time of the first clock edge
  	sc_clock clockSource("clock",period, duty, delay ); // define the clock source

	//Declare the instance of Watch class
	Watch wtc("watch");
		
	//Binding the clock input port of the watch with the clock source
	wtc.clkInput(clockSource);				

	//Debugger setting
	sc_trace_file *handle;
	handle = sc_create_vcd_trace_file("waveforms");
	sc_trace(handle, wtc.clkInput, "Clock");

	//Start simulation
	sc_start(4000,SC_SEC);

	//Simulation is finished
	cout << endl <<"simulation finished" << endl;
	sc_close_vcd_trace_file(handle);
	system("pause");
	return 0;
}
