#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
This function returns the sum of all the multiples
of mult_value below max_value.
*/
int sum_of_mults(int mult_value, int max_value) {
  int result = 0;

  for(int i = mult_value; i < max_value; i += mult_value) {
    result += i;
  }
  return result;
}




int main(int argc, char *argv[]) {

  int mult_3 = sum_of_mults(3, 1000);
  int mult_5 = sum_of_mults(5, 1000);
  int mult_15 = sum_of_mults(15, 1000);
  
  int output = mult_3 + mult_5 - mult_15;
  
  printf("\nThe answer is: %d\n", output);
  
  return 0;

}
