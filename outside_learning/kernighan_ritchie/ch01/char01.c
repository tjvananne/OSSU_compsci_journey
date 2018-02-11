#include <stdio.h>

/* File copying - copy input to output one character at a time 

read a character
while (character is not end-of-file indicator)
  output the character just read in
  read a character
  next iteration
*/

int main(void) 
{

  int c;

  c = getchar(); 
  while (c != EOF) {
    if (c == '\r') { break; }
    putchar(c);
    c = getchar();
  }  


}
