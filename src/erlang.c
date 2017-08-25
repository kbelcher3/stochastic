#include <math.h>
#include "distributions.h"

// Returns an Erlang(k, lambda) rv
double erlang(int k, double lambda) {
	// Sanity checks
	if(k<1 || lambda<0)
		return -1;
	
	// Sum k expo(lambda) rv's
	double return_value = 0;
	for(int i=0; i<k; i++)
		return_value += expo(lambda);

	return return_value;
}
