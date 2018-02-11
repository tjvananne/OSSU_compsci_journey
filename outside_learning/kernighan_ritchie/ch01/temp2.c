#include <stdio.h>

int main(void) 
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);

    // %3.0f is float with three spaces before decimal and 0 after?
    // %6.1f is float with six spaces before decimal and 1 after
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;  


  }

}
