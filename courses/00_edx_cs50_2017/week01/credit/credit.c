#include <stdio.h>

# define VERBOSE 1

/* Next steps:

1) I need to add some logic to verify if the number is valid based on first few digits and number of digits provided
	- hard-coded rules based on credit card company card number rules
2) capture length of their input, reverse the index, then isolate only the odd indeces (make function out of this?)
3) do the same as #2, but isolate only the even indeces (starting at zero)
4) calculate the Luhn algorithm for validating the credit card
*/


int main(void)
{
  
  //declare ccnum (credit card number) to be array of 16 places
  int ccnum[16];
  
  // initialize all to zero
  int i, c;
  for (i = 0; i < 16; i++) {
    ccnum[i] = 0;
  }

  // make sure it's initialized to all zeros?
  if(VERBOSE) {
    printf("testing if they are all zero\n");
    for(int j = 0; j < 16; j++) {
      printf("%d", ccnum[j]);
    }
    printf("\n");
  }


  i = 0;
  while ((c = getchar()) != EOF && i < 16) {
    if (c >= '0' && c <= '9') {
      
      if(VERBOSE) {
        printf("value of c is %c and numeric value is %d\n", c, c - '0');
        printf("value of i is %d\n", i);
      }
      
      if(i > 16)
        printf("Ignoring digits after 16 - no credit card should have more than 16 digits\n");


      ccnum[i] = (c - '0');
      i++;  
    }
  }
  
  i = 0;
  printf("printing them all out to see their value\n");
  for (i = 0; i < 16; i++) {
    printf("%d", ccnum[i]);
  }
  
  printf("\n");

}





