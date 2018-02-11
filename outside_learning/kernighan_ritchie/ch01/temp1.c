#include <stdio.h>


int main(void) 
{

  // variable declarations
  int fahr, celsius;
  int lower, upper, step;

  // values
  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  
  // start the while loop, go until fahr is above upper limit  
  while (fahr <= upper) {

    // actual calculation of celsius from fahrenheit value
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }

}
