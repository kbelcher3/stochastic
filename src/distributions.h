#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H
#endif

/**************************
 * Discrete distributions *
 **************************/


// Returns a Bernoulli(p) rv
// P(X=1) = p = 1 - P(X=0)
int ber(double *p);

// Returns a Rademacher rv
// P(X=1) = 1/2 = P(X=-1)
int rademacher();

// Returns a Binomial(n, p) rv
// P(X=k) = Binom(n, k) * p^k * (1-p)^(n-k)
int binom(int *n, double *p);

// Returns a Geometric(p) rv
// P(X=k) = (1-p)^(k-1)*p
int geom(double *p);

// Returns a Poisson(lambda) rv
// P(X=k) = exp(-lambda)*lambda^k/k!
int pois(double *lambda);

// Returns a discrete uniform distribution on {0, n}
// P(X=k) = 1/(n+1), k=0,1,...,n
int disc_unif(int *n);


/****************************
 * Continuous distributions *
 ****************************/

// Returns a U(0,1) rv
// f(x) = 1, 0<x<1
double unif();

// Returns a U(a,b) rv
// f(x) = 1/(b-a), a<x<b
double unif_ab(int *a, int *b);

// Returns a Exp(lambda) rv
// f(x) = lambda*exp(-lambda*x), 0<x<inf
double expo(double *lambda);

// Returns a N(mu, sigma2) rv
// f(x) = 1/sqrt(2*pi*sigma2)*exp(-((x-mu)/sigma)^2/2), -inf<x<inf
double N(double *mu, double *sigma2);



