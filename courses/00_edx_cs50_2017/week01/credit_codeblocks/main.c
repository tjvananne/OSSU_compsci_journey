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

  // I don't know how to handle errors properly, so I'm only reading in
  // 20 valid characters (digits)

  // order of operations:
  // 1) loop to read in maximum of 20 characters - stop if EOF is read in
  // 2) keep a count of just the integers (>= '0' & <= '9')
  // 3) std in gets to EOF
  // 4) initialize an array of length of count kept in #2
  // 5) do all of the validations based on different cc companies and # digits
  // 5.1) create the flag here for which cc company the card belongs to
  // 6) calculate Luhn algorithm for credit card to determine if valie
  // 7) if #6 shows valid Luhn algo, then return the cc company, else "INVALID"

  printf("Please enter credit card number below:\n");

  // initializing some space for user input
  int max_input_length = 20;
  int user_input[max_input_length];
  int i;
  for (i = 0; i < max_input_length; i++)
    user_input[i] = 0;


  //capturing user input - isolating just the digits
  int c;
  int valid_indx = 0;

  for (i = 0; i < max_input_length; i++) {
    if ((c = getchar()) == EOF) {
      break;
    } else {
      if (c >= '0' & c <= '9') {
        user_input[valid_indx] = c;
        valid_indx++;
      }
    }
  }

  // print the card number back to the user
  printf("\n");
  for (i = 0; i < valid_indx; i++) {
    printf("%c", user_input[i]);
  }
  printf("\n");


  // print reverse index for practice - cool, that works
  // this is first step in luhn algo
  for (i = valid_indx; i > 0; i--) {
    printf("%c, ", user_input[(i - 1)]);
  }





  printf("\n");



  // test for amex (starts with 34 or 37 and is 15 digits)
  if (user_input[0] == '3' && (user_input[1] == '4' ||
      user_input[1] == '7') && valid_indx == 15) {
    printf("AMEX!");
  } else {
    printf("not amex!, valid_indx is %d\n", valid_indx);
  }






}


  // OLD
  /*

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

*/


