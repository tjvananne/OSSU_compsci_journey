#include <stdio.h>

#include "cs50.h"
#include "helpers.h"

int main(void)
{

    string x = get_string("enter a fraction in format X/Y: ");    
    
    int dur = duration(x);
    printf("duration of fraction = %d\n", dur);

}
