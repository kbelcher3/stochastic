#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv) {
  srand48(time(NULL));
  for(int i=0; i < 10; i++) {
    printf("%g\n", drand48())
  }
  return 0;
}
