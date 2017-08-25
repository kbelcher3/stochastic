#include <math.h>
#include "distributions.h"

// Returns a N(mu, sigma2) rv
double normal_rv(double mu, double sigma2) {
	// Sanity check
	if(sigma2 < 0)
		return -1;

	// Use Box-Muller transform
	int u = unif();
	int v = unif();

	return sqrt(-2*log(u)*cos(2*M_PI*v));
}
