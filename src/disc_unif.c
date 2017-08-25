#include "distributions.h"
#include <math.h>

// Returns a discrete uniform distribution on {0, n}
int disc_unif(int n) {
	double u = unif();
	
	// Use standard method of generating discrete rv
	for(int i=0; i<=n; i++) {
		if(u < (i+1)/(n+1))
			return i;
	}
}
