#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height = get_int("Height: ");
    
    printf("they wanted height of: %d\n", height);

    int num_spaces = height - 1;
    int num_hashes = 1;             // could be a constant?
    
    // row
    for(int i = 0; i < height; i++)
    {
        // write dynamic number of spaces
        for(int j = 0; j < num_spaces; j++)
        {
            printf(" ");
        }

        // write dynamic number of hashes
        for(int k = 0; k < num_hashes; k++)
        {
            printf("#");
        }

        // write some spaces to separate
        printf("   ");

        // write dynamic number of hashes
        for(int k = 0; k < num_hashes; k++)
        {
            printf("#");
        }

        // new line
        printf("\n");
 
        // increment / decrement
        num_spaces = num_spaces - 1;
        num_hashes = num_hashes + 1;

    }




}
