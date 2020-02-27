#include "watch.h"

SC_HAS_PROCESS(Watch);
Watch::Watch(sc_module_name nm)
:sc_module(nm), counterSeconds(60), counterMinutes(60), counterHours(24)
{
	SC_THREAD(IncSeconds);
	SC_THREAD(IncMinutes);
	SC_THREAD(IncHours);
	SC_THREAD(Display);
}

void Watch::IncSeconds()
{
	bool overFlowSeconds = false;

	for(;;)
	{
		//wait until rising edge of clock is detected
		wait(clkInput.posedge_event());

		//Increase the seconds
		counterSeconds.count();
		
		//If overflow is detected, then it triggers IncMinutes process
		overFlowSeconds = counterSeconds.overflow();
		if(overFlowSeconds != false)
		{
			next_minute.notify();
		}
	}

}

void Watch::IncMinutes()
{
	bool overFlowMinutes = false;

	for(;;)
	{
		//wait until it is triggered by the IncSeconds process 
		wait(next_minute);
		
		//Increase the minutes
		counterMinutes.count();
		
		//If overflow is detected, then it triggers IncHours process
		overFlowMinutes = counterMinutes.overflow();
		if(overFlowMinutes != false)
		{
			next_hour.notify();
		}

	}
}


void Watch::IncHours()
{
	bool overFlowHours = false;

	for(;;)
	{
		//wait until it is triggered by the IncMinutes process 
		wait(next_hour);
		
		//Increase the hours
		counterHours.count();
		
		//If overflow is detected, then it do nothing
		overFlowHours = counterMinutes.overflow();
		if(overFlowHours != false)
		{
			// Do nothing
		}

	}
}

void Watch::Display()
{
	for(;;)
	{
		//wait until falling edge of clock is detected 
		wait(clkInput.negedge_event());
		
		//display the seconds, the minutes, and the hours
        cout<<"Time stamp="<<sc_time_stamp()<<" --> (HH:MM:SS) ";
		cout<<counterHours.read()<<":"<<counterMinutes.read()<<":"<<counterSeconds.read()<<endl;
	}
}
