#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "distributions.h"

// Returns a U(0,1) rv
double unif() {
	return (double)rand() / (double)RAND_MAX;
}

// Generates a Ber(p) random  variate
int ber(double p) {
	double u = unif();
	
	if(u > p) 
		return 0;
	else 
		return 1;
}

// Returns a Rademacher rv
int rademacher() {
	int temp_ber = ber(0.5);
	return (2*temp_ber)-1;
}



// Returns a discrete uniform distribution on {0, n}
int disc_unif(int n) {
	double u = unif();
	
	// Use standard method of generating discrete rv
	for(int i=0; i<=n; i++) {
		if(u < (i+1)/(n+1))
			return i;
	}
}

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

// Returns a Geometric(p) rv
int geom(double p) {
	// Sanity checks
	if(p < 0 || p > 1)
		return -1;
	
	int return_value = 1;
	// Use memoryless property to generate the rv
	int stop_loop = 0;
	while(stop_loop == 0) {
		if(unif() > p)
			return_value++;
		else
			stop_loop = 1;
	}

	return return_value;
}

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

// Returns a Borel rv with parameter mu in [0,1]
int borel(double mu) {
	// Sanity check
	if(mu < 0 || mu > 1) 
		return -1;
	
	return 0;
}


// Returns a U(a,b) rv
double unif_ab(double a, double b) {
	// Sanity check
	if(a > b)
		return -1;
	
	// Scale a U(0,1) rv
	return unif()*(b-a) + a;
}

// Returns a Triangular(a, b, c) rv
double triangular(double a, double b, double c) {
	// Sanity checks
	if(a>b || a>c || b>c)
		return -1;

	// Use inverse transform method
	double F_c = (c-a)/(b-a);

	if(unif() < F_c)
		return a + sqrt(unif()*(b-a)*(c-a));
	else
		return b - sqrt((1-unif())*(b-a)*(b-c));
}

// Returns a Exp(lambda) rv
double expo(double lambda) {
	// Sanity check
	if(lambda < 0)
		return -1;
	
	// Use inverse transform method
	return -1*log(unif())/lambda;
}

// Returns a Laplace(mu, b) rv
double laplace_rv(double mu, double b) {
	// Sanity check
	if(mu < 0) 
		return -1;

	// Use inverse transform method
	double u = unif_ab(-0.5, 0.5);
	if(u<0)
		return mu - b*(-1)*log(1-2*abs(unif()));
	else
		return mu - b*log(1-2*abs(unif()));
}

// Returns an Erlang(k, lambda) rv
double erlang(int k, double lambda) {
	// Sanity checks
	if(k<1 || lambda<0)
		return -1;
	
	// Sum k expo(lambda) rv's
	double return_value = 0;
	for(int i=0; i<k; i++)
		return_value += expo(lambda);

	return return_value;
}

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

// To be implemented later
double weibull_rv(double k, double lambda) {
	return -1;
}
// To be implemented later
double gamma_rv(double k, double b) {
	return -1;
}
