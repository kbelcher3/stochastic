#include <math.h>
#include "distributions.h"

// Returns a Poisson(lambda) rv
int pois(double lambda) {
	// Sanity checks
	if(lambda < 0)
		return -1;

	// Knuth's algorithm
	double L = exp(-1*lambda);
	int k = 0;
	double p = 1;

	do {
		k++;;
		p = p*unif();
	}
	while(p > L);

	return k-1;
}
