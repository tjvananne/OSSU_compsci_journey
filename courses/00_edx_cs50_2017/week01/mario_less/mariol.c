#include <stdio.h>
#include "cs50.h"

int main(void)
{

    int height = get_int("Height: ");
    printf("you entered: %d\n", height);

    int number_of_spaces = height - 1;
    int number_of_hashes = 2;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < number_of_spaces; j++)
        {
            printf(" ");
        }        
        for(int k = 0; k < number_of_hashes; k++)
        {
            printf("#");
        }
        
        printf("\n");
        number_of_spaces = number_of_spaces - 1;
        number_of_hashes = number_of_hashes + 1;

    }


}
