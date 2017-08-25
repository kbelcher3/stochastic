#include <math.h>
#include "distributions.h"

// Returns a Exp(lambda) rv
double expo(double lambda) {
	// Sanity check
	if(lambda < 0)
		return -1;
	
	// Use inverse transform method
	return -1*log(unif())/lambda;
}
