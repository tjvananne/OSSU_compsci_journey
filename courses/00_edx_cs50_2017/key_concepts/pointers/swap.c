#include <stdio.h>

void swap(int *px, int *py);

int main(void)
{

    int x = 1;
    int y = 7;

    printf("x = %d\n y = %d\n\n", x, y);

    printf("after swap:\n");
    swap(&x, &y);

    printf("x = %d\n y = %d\n\n", x, y);
}



void swap(int *px, int *py)
{

    // initialize a placeholder
    int temp;

    // set it equal to the value stored in address of x
    temp = *px;

    // now set the value of what is stored in address of x to value of what
    // is stored in address of y
    *px = *py;

    // finally, set the value of what is stored in address of y equal to
    // the value we stored in int temp
    *py = temp;  // <-- already an int, no need to de-reference


}

