#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "distributions.h" 

// Note: RAND_MAX = 2147483647 = 2^(31)-1  

int ber(double *p) {
  return unif() > *p ? 0 : 1;
}

int rademacher() {
  return unif() > 0.5 ? -1 : 1;
}

int binom(int *n, double *p) {
  int output = 0;
  for(int i=0; i<*n; i++)
    output += ber(p);
  return output;
}


int geom(double *p) {
  return unif() > *p ? 1 : 1 + geom(p);
}



double unif() {
  return (double)rand() / (double)RAND_MAX;
}



int main(int argc, char **argv) {

  srand(time(NULL));

  return 0;
}
