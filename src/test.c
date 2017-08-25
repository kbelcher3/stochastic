#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "distributions.h"
#include "distributions.c"


int main(int argc, char **argv) {
	// Seed the RNG
	srand(time(NULL));
	
	for(int i=0; i<20; i++)
		printf("%d, ", rademacher());

	return 0;
}
