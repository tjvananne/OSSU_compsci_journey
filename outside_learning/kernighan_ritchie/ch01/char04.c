#include <stdio.h>

/* count the lines in the input */

int main(void) 
{

  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
  }
  
  printf("\n%d\n", nl);



}
