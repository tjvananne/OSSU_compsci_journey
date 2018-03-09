#include <stdio.h>

int main(void) 
{

    int i = 0;

    // recursion could be useful for this step counter type thing... this works for now though
    while ((i + 10000 > i)) {
        i = i + 10000;        
    }

    while ((i + 1 > i)) {
        i++;
    }


    // purposeful overflow
    int min = i + 1;


    printf("max value of int: %d\n", i);
    printf("min value of int: %d\n", min);

}



