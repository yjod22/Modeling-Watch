#ifndef _WATCH_H_
#define _WATCH_H_
#include "systemc.h"
#include "counter.h"

#define ENABLE_CPLUSPLUS_STYLE
#ifdef ENABLE_CPLUSPLUS_STYLE
class Watch : public sc_module
{
	public:		  
		//Constructor
		Watch(sc_module_name nm);

		// data members (attributes)
		sc_in<bool> clkInput;
		sc_event next_minute;
		sc_event next_hour;

		//Instances
		Counter counterSeconds;
		Counter counterMinutes;
		Counter counterHours;

		// member functions (methods)
		void IncSeconds();
		void IncMinutes();
		void IncHours();
		void Display();
};
#endif

#ifdef ENABLE_SYSTEMC_STYLE
SC_MODULE(Watch)
{
	public:		  
		//Constructor
		Watch(sc_module_name nm);

		// data members (attributes)
		sc_in<bool> clkInput;
		sc_event next_minute;
		sc_event next_hour;

		//Instances
		Counter counterSeconds;
		Counter counterMinutes;
		Counter counterHours;

		// member functions (methods)
		void IncSeconds();
		void IncMinutes();
		void IncHours();
		void Display();
};
#endif
	
#endif