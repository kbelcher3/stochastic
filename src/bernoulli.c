#include <stdio.h>
#include <stdlib.h>

// Generates a Ber(p) random  variate
int ber(double p) {
	double u = rand();
	
	if(u > p) 
		return 0;
	else 
		return 1;
}
