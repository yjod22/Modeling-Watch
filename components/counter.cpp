#include "counter.h"

Counter::Counter(sc_uint<8> mod)
{
	modulus = mod;
	overflow_flag = false; 
	state=0;
}

void Counter::count()
{
	if(state==(modulus-1))    
	{ 
		overflow_flag = true;
		state = 0;
	}
	else
		state = state+1;
}

bool Counter::overflow()
{
	if(overflow_flag==true) 
	{ 
		overflow_flag = false;
		return true;
	}
	else
		return false;
}

sc_uint<8> Counter::read_mod()
{
	return modulus;
}

class Counter : public Register 
{
	private:
		// data members (attributes)
		sc_uint<8> modulus;
		bool overflow_flag;

	public:
		// member functions (methods)
		Counter(sc_uint<8> mod)
		{
			modulus = mod;
			overflow_flag = false; 
			state=0;
		}
};

#endif
