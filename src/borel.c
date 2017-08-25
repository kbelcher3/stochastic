#include <math.h>
#include "distributions.h"

// Returns a Borel rv with parameter mu in [0,1]
int borel(double mu) {
	// Sanity check
	if(mu < 0 || mu > 1) 
		return -1;
	
	return 0;
}
