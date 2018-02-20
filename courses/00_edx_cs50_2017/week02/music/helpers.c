// Helper functions for music

#include <cs50.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // if we can safely assume X/Y format to be constant...
    int X = fraction[0] - '0';
    int Y = fraction[2] - '0';
    return (X * (8 / Y));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0') {
        return true;
    } else {
        return false;
    }
}
