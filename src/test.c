#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "distributions.h"


int main(int argc, char **argv) {
	// Seed the RNG
	srand(time(NULL));
	
	for(int i=0; i<20; i++)
		printf("%0.4f\n", expo(1));

	return 0;
}
