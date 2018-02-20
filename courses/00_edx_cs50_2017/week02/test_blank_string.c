#include <stdio.h>
#include <string.h>
#include "cs50.h"

int main(void) 
{
    
    string x = get_string("type a string plz: ");
    //string x = "\n";
    printf("user typed: %s\n", x);

    printf("first char as int: %d\n", x[0]);

    // printf("user input as int: %d\n", x);

    printf("string length of input: %zu\n", strlen(x));


    if (x == NULL) {
        printf("yes, the user's entry is equal to NULL\n");
    } else if (x == " ") {
        printf("yes, its an empty space\n");
    
    } else if (x[0] == '\0') {
        printf("Equal to a single null byte character\n");
    } else if (x == "") {
        printf("Yes, equal to empty double quotes\n");
    
    } else if (x == "\0") {
        printf("yes, backslash zero inside of double quotes\n");        
    /*
    } else if (x == '\r') {
        printf("Equal to carriage return\n");
    } else if (x == '\n') {
        printf("Equal to new line character \n");
    */
    
    } else if (x == 0) {
        printf("yes, x is equal to the integer zero\n");

    } else {
        printf("no, keep trying to find what this is equal to\n");
    }

}
