#include <stdio.h>

int main(void)
{

    // first the to understand - initializing a pointer (<data type> *) - data type and then star
    int* p_int;
    char* p_char;

    // above statements initialize a pointer variable that now points
    // to a random address in memory (RAM)
    printf("Let's print these addresses out:\np_int address: %p\np_char address: %p\n", (void*)p_int, (void*)p_char);
    
    // now we can declare our own actual variables and tell the
    // pointers we previously declared to point there
    int my_int = 7;
    char my_char = 'G';

    // this is done using the "&" character before the name of the variable (&<variable name>)
    p_int = &my_int;
    p_char = &my_char;

    // now let's reprint the addresses of these locations    printf("\n");
    printf("\nLet's print these addresses out:\np_int address: %p\np_char address: %p\n", (void*)p_int, (void*)p_char);
 
    // we can tell the compiler to go get the value sitting at the address of the pointer by de-referencing the pointer
    // (*<pointername>) - star followed by pointer name
    printf("\nvalue inside address of p_int: %d\nvalue inside address of p_char: %c\n", *p_int, *p_char);

    // now if we want to do any pointer arithmetic
    printf("\nint address before: %p\nint address after adding 1: %p\n", (void*) p_int, (void*) (p_int + 1));
    printf("\nchar address before: %p\nchar address after adding 1: %p\n", (void*) p_char, (void*) (p_char + 1));

     
  
}
