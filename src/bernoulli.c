#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

// Generates a Ber(p) random  variate
int ber(double p) {
	double u = drand48();
	
	if(u > p) 
		return 0;
	
	else 
		return 1;
	
}


int main(int argc, char *argv[]) {
	// Seed the p-rng
	srand48(time(NULL));
	
	// Set the parameter
	double p;
	sscanf(argv[1], "%lf", &p);
	

	// Set the number of trials
	int n;
	sscanf(argv[2], "%d", &n);

	// Print out some variates
	for(int i=0; i < n; i++) 
		printf("%d", ber(p));
	

	return 0;
}
