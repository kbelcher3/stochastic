#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "distributions.h"

// Returns a Binomial(n, p) rv
int binom(int n, double p) {
	// Sanity checks
	if(n<1 || p < 0 || p > 1)
		return -1;
	
	// Add n Bernoulli(p) rv's
	int return_value = 0;
	for(int i = 0; i < n; i++) {
		return_value += ber(p);
	}

	return return_value;
}
