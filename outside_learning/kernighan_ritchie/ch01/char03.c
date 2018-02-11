#include <stdio.h>

/* count characters fed in through standard input 

when you're done typing in characters, you have to hit (CTRL + D) twice to run the character count calculation
*/

int main(void)
{
  long nc;

  nc = 0;

  while (getchar() != EOF) {
    ++nc;
  }
  printf("\n%ld\n", nc);

}



