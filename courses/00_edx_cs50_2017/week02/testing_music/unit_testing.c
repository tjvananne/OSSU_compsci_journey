#include <stdio.h>
#include <math.h>
#include "cs50.h"
#include "helpers.h"

int unit_test_freq(string note);

int main(void)
{
    /*
    string x = get_string("enter a fraction in format X/Y: ");    
    
    int dur = duration(x);
    printf("duration of fraction = %d\n", dur);
    */

    printf("unit testing starting\n");

    unit_test_freq("C0");
    unit_test_freq("A0");
    unit_test_freq("C4");
    unit_test_freq("A4");        

}

int unit_test_freq(string note) {
    printf("testing string note: %s\n", note);
    int freq = frequency(note);
    printf("resulting frequency: %d\n\n", freq);
}



