#include <stdio.h>
#include <cs50.h>

// tell the compiler that this function will be defined later
void print_n_times(char g, int n);


int main(void)
{

    // get the height of the structure
    int height = get_int("Height: ");
    
    // printf("they wanted height of: %d\n", height);

    int num_spaces = height - 1;
    int num_hashes = 1;             // could be a constant?
    
    // for each row...
    for(int i = 0; i < height; i++)
    {
        // use user defined function for number of characters
        print_n_times(' ', num_spaces);
        print_n_times('#', num_hashes);
        
        // write some spaces to separate
        printf("  ");

        print_n_times('#', num_hashes);        

        // new line
        printf("\n");
 
        // increment / decrement number of spaces / hashes
        num_spaces = num_spaces - 1;
        num_hashes = num_hashes + 1;

    }
}


// user-defined function to print a character a certain number of times (no new line)
void print_n_times(char c, int n) 
{
    for(int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}




