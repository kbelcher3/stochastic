#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <math.h>


/*
This function uses the standard recurrence

    Fib[n+2] = Fib[n+1] + Fib[n], Fib[1] = Fib[2] = 1

which has exponential runtime. 
*/
long int bad_fib(long int n, long int *ct) {
  // Increment the counter
  *ct += 1;

  // Error case
  if(n < 0) {
    return(-1);
  }
  
  // Base cases
  if(n < 2) {
    return(1);
  }

  // Recursion
  return(bad_fib(n-1, ct) + bad_fib(n-2, ct));
}

/*
This function uses memoization which has linear runtime!
*/
long int good_fib(long int n) {
  // Array is of size n+1 due to 0-indexing
  long *fibb = malloc((n+1) * sizeof *fibb);

  // Base cases
  fibb[0] = 1;
  fibb[1] = 1;

  // Iterate to compute the Fibonacci numbers
  for(int i = 0; i < n-1; i++) {
    fibb[i+2] = fibb[i+1] + fibb[i];
  }

  return(fibb[n]);

}


int main(int argc, char *argv[]) {

  // Command-line arg stuff
  int base;
  char *endptr, *str;
  long n;
  
  if(argc < 2) {
    fprintf(stderr, "Usage: %s str [base]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  str = argv[1];
  base = (argc > 2) ? atoi(argv[2]) : 10;

  errno = 0;
  n = strtol(str, &endptr, base);

  if((errno == ERANGE && (n == LONG_MAX || n == LONG_MIN))
        || (errno != 0 && n == 0)) {
    perror("strtol");
    exit(EXIT_FAILURE);
  }


  // Program starts here

  // Count the number of times the bad_fib() function is called.
  long int count = 0;
  long int *count_ptr = &count;

  // Compute!
  long int output = bad_fib(n, count_ptr);
  long int output2 = good_fib(n);


  // Print output
  printf("\n(Good) Fib[%ld] = %ld\n", n, output2);

  printf("\n(Bad) Fib[%ld] = %ld", n, output);
  printf("\nNumber of times bad_fib() called: %ld\n", count);
  
  return 0;
}
