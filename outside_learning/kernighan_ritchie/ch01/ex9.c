#include <stdio.h>

#define ONESPACE ' '

/* Copy standard input to standard output. If you run into a scenario where
there are consecutive spaces, only print one of them. */


int main(void)
{
  
  int c;  
  
  while ((c = getchar()) != EOF) {
    
    // if the character is a space - keep getting new chars until not a space - then put a space
    if (c == ONESPACE) { 
      while (c == ONESPACE) {
        c = getchar();
      }
      putchar(ONESPACE);
    }
    
    // otherwise, just put the same char we read in
    putchar(c);
  }  
}




