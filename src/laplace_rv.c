#include <math.h>
#include <stdlib.h>
#include "distributions.h"

// Returns a Laplace(mu, b) rv
double laplace_rv(double mu, double b) {
	// Sanity check
	if(mu < 0) 
		return -1;

	// Use inverse transform method
	double u = unif_ab(-0.5, 0.5);
	if(u<0)
		return mu - b*(-1)*log(1-2*abs(unif()));
	else
		return mu - b*log(1-2*abs(unif()));
}
