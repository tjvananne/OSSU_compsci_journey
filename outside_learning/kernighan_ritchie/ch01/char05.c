#include <stdio.h>

#define IN 1   /* we're inside a word */
#define OUT 0  /* we're outside a word */

/* count lines, wordss, and characters in input */

int main(void) 
{

  int c, nl, nw, nc, state;

  // state defaults to us being "outside" of a character string (word)
  state = OUT;
  nl = nw = nc = 0;
  while ( (c = getchar() ) != EOF) {
    
    // nc is a count of characters
    ++nc;

    // if c is a newline, increment our newline variable
    if (c == '\n')
      ++nl;
    
    // if blank, newline, or tab character, then set state to outside of a word
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;

    // if state is already "OUT" and character c isn't blank, newline, or tab... 
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }

  }
 
  printf("\n%d %d %d\n", nl, nw, nc);

}




