#include <math.h>
#include "distributions.h"

// Returns a U(a,b) rv
double unif_ab(double a, double b) {
	// Sanity check
	if(a > b)
		return -1;
	
	// Scale a U(0,1) rv
	return unif()*(b-a) + a;
}
