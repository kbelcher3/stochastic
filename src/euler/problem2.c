#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <math.h>



/*
This function uses memoization which has linear runtime!
*/
long int *good_fib(long int n) {
  // Array is of size n+1 due to 0-indexing
  long *fib = malloc((n+1) * sizeof *fib);

  //
  
  // Base cases
  fib[0] = 1;
  fib[1] = 1;

  // Iterate to compute the Fibonacci numbers
  for(int i = 0; i < n-1; i++) {
    fib[i+2] = fib[i+1] + fib[i];
  }

  return(fib);
}


int main(int argc, char *argv[]) {

  long int n = 33;
  long int *fib = good_fib(n);

  long int sum_of_evens = 0;

  printf("\n");

  for(int i = 1; i <= n; i += 3) {
    sum_of_evens += fib[i];
  }

  printf("\nAnswer: %ld\n", sum_of_evens);
    
  return 0;
}
