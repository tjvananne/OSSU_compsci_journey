#include <stdio.h>

# define VERBOSE 0

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
      //only add numeric characters to the user input, remaining indeces of array are 0's
      if (c >= '0' & c <= '9') {
        user_input[valid_indx] = c;
        valid_indx++;
      }
    }
  }

  if (VERBOSE) { printf("\n"); }

  // print the card number back to the user (only the valid entries)

  if (VERBOSE) {
    printf("\n");
    for (i = 0; i < valid_indx; i++) {
      printf("%c", user_input[i]);
    }
    printf("\n");
  }



  // print reverse index for practice - cool, that works
  // this is first step in luhn algo

  // this int is a flag for when to multiply by two or not (every other one)
  int multiply_by_two, this_digit, sum_of_twos, sum_of_ones, digit_doubled;
  multiply_by_two = this_digit = sum_of_twos = sum_of_ones = digit_doubled = 0;

  // start at last valid entry and work your way back...
  for (i = valid_indx; i > 0; i--) {

    // subtract 1 from valid digit index to get the real value within the array
    this_digit = user_input[(i - 1)] - '0';

    // if this flag is set to 1, multiply the digit by two
    if (multiply_by_two == 1) {
      digit_doubled = this_digit * 2;

      // if the doubled digit is above ten, we need to add the two individual digits together
      if (digit_doubled >= 10) {
        sum_of_twos = sum_of_twos + 1;                    // adding the 1 for the tens place
        sum_of_twos = sum_of_twos + (digit_doubled % 10); // add the remainder
      } else {
        sum_of_twos = sum_of_twos + digit_doubled;
      }
      multiply_by_two = 0;
    } else {
      sum_of_ones = sum_of_ones + this_digit;
      multiply_by_two = 1;
    }
  }


  if ((sum_of_twos + sum_of_ones) % 10 != 0) {
    printf("INVALID\n");
    return(0);
  }

  printf("\n");

  // test for amex (starts with 34 or 37 and is 15 digits)
  if (user_input[0] == '3' && (user_input[1] == '4' ||
      user_input[1] == '7') && valid_indx == 15) {
    printf("AMEX\n");
  }

  // test for master card (first digit 5, second digit 1-5, length of card is 16 digits
  if (user_input[0] == '5' && user_input[1] > '0' &&
      user_input[1] < '6' && valid_indx == 16) {
    printf("MASTERCARD\n");
  }

  // test for visa (13 or 16 digits and starts with a 4)
  if (user_input[0] == '4' && (valid_indx == 13 || valid_indx == 16)) {
      printf("VISA\n");
  }


}

