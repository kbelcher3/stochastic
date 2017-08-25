#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H
#endif

#include <math.h>

/**************************
 * Discrete distributions *
 **************************/


// Returns a Bernoulli(p) rv
// P(X=1) = p = 1 - P(X=0)
int ber(double p);

// Returns a Rademacher rv
// P(X=1) = 1/2 = P(X=-1)
int rademacher();

// Returns a Binomial(n, p) rv
// P(X=k) = Binom(n, k) * p^k * (1-p)^(n-k)
int binom(int n, double p);

// Returns a Geometric(p) rv
// P(X=k) = (1-p)^(k-1)*p
int geom(double p);

// Returns a Poisson(lambda) rv
// P(X=k) = exp(-lambda)*lambda^k/k!
int pois(double lambda);

// Returns a discrete uniform distribution on {0, n}
// P(X=k) = 1/(n+1), k=0,1,...,n
int disc_unif(int n);

// Returns a Borel rv with parameter mu in [0,1]
// P(X=k) = e^(-mu * k)(mu * k)^(k-1)/(k!)
int borel(double mu);

/****************************
 * Continuous distributions *
 ****************************/

// Returns a U(0,1) rv
// f(x) = 1, 0<x<1
double unif();

// Returns a U(a,b) rv
// f(x) = 1/(b-a), a<x<b
double unif_ab(double a, double b);

// Returns a Exp(lambda) rv
// f(x) = lambda*exp(-lambda*x), 0<x<inf
double expo(double lambda);

// Returns a N(mu, sigma2) rv
// f(x) = 1/sqrt(2*pi*sigma2)*exp(-((x-mu)/sigma)^2/2), -inf<x<inf
double normal_rv(double mu, double sigma2);

// Returns a Triangular(a, b, c) rv
// f(x) = 2(x-a)/((b-a)*(c-a)), a<=x<c
//        2(b-x)/((b-a)*(b-c)
double triangular(double a, double b, double c);

// Returns a Gamma rv with shape parameter k and scale parameter b
// f(x) = 1/(Gamma(k)*b^k) * x^(k-1)*e^(-x/b)
double gamma_rv(double k, double b);

// Returns an Erlang(k, lambda) rv
// f(x) = (lambda * x)^(k-1)/((k-1)!) * lambda * e^(-lambda * x)
double erlang_rv(int k, double lambda);

// Returns a Weibull(k, lambda) rv
// f(x) = (k/lambda) * (x/lambda)^(k-1) * e^(-x/lambda)^k
double weibull_rv(double k, double lambda);

// Returns a Laplace(mu, b) distribution
// f(x) = 1/(2*b) * e^(-|x-mu|/b)
double laplace_rv(double mu, double b);





