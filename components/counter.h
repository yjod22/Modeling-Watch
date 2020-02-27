#ifndef _COUNTER_H_
#define _COUNTER_H_
#include "systemc.h"
#include "register.h"

class Counter : public Register 
{
	private:
		// data members (attributes)
		sc_uint<8> modulus;
		bool overflow_flag;

	public:
		// Constructor
		Counter(sc_uint<8> mod);
	
		// member functions (methods)
		void count();
		bool overflow();
		sc_uint<8>  read_mod();
};

#endif
