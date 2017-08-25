#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "distributions.h"

// Returns a Rademacher rv
int rademacher() {
	int temp_ber = ber(0.5);
	return (2*temp_ber)-1;
}
