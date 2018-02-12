#include <stdio.h>

/* count digits, white space, others */

int main(void) 
{

  // declare some ints and an int array
  int c, i, nwhite, nother;
  int ndigit[10];

  // set initial value to zero
  nwhite = nother = 0;

  // loop through all the items in the array and set them all to zero (they'll initialize to trash values)
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  // loop through
  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];  // this subsetting is genius; c - '0' will give the correct array index value for our array
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  
  // '0' is the first possible value we want to capture in our array
  // subtracting c by '0' will mean that a value of '0' will equal the integer value 0
  // a value of '1' - '0' will equal integer value 1, and so on

  printf("digits =");
  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);



}



