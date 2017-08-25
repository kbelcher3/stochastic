#include <math.h>
#include "distributions.h"

// Returns a Triangular(a, b, c) rv
double triangular(double a, double b, double c) {
	// Sanity checks
	if(a>b || a>c || b>c)
		return -1;

	// Use inverse transform method
	double F_c = (c-a)/(b-a);

	if(u < F_c)
		return a + sqrt(unif()*(b-a)*(c-a));
	else
		return b - sqrt((1-unif())*(b-a)*(b-c));
}
