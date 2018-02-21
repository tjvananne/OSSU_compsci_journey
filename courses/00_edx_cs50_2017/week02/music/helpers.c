// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

#define A4SEMITONES 57


int find_in_array(char *findthis, char *inthis[], int length_of_in_this);


 
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
    // Basic steps:
    // 1) identify if string is 2 or 3 characters, otherwise return an error
    // 2) calculate the semitones
    // 3) find the difference between semitones of this string and the A4 440 string
    // 4) calculate and return the frequency of the note based on difference in semitones from A4

    char *notes[17] = {"C", "C#", "Db", "D", "D#", "Eb", "E", "F", "F#", "Gb", "G", "G#", "Ab", "A", "A#", "Bb", "B"}; 
    int note_vals[17] = {0, 1, 1, 2, 3, 4, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 11};
   
    // 1)
    int note_str_len = 0;
    while (note[note_str_len] != '\0') {
        note_str_len++;
    } 

    if (note_str_len == 2) {
        //handle 2 char string
        char this_note[2];
        this_note[0] = note[0];
        this_note[1] = '\0';
        
        // 2) 
        int X = note_vals[find_in_array(this_note, notes, 17)];
        int Y = (note[1] - '0') * 12;
        // printf("semitones: %d\n", (X + Y));
        
        // 3 & 4)
        double semitones_from_A4 = ((double) X + (double) Y) - (double) A4SEMITONES;
        double exponential = semitones_from_A4 / 12.0;
        int frequency = round(pow(2.0, exponential) * 440.0);
       
        return (frequency);

    } else if (note_str_len == 3) {
        //handle 3 char string
        char this_note[3];
        this_note[0] = note[0];
        this_note[1] = note[1];
        this_note[2] = '\0';

        // 2)
        int X = note_vals[find_in_array(this_note, notes, 17)];
        int Y = (note[2] - '0') * 12;
        // printf("semitones: %d\n", (X + Y));
        
        // 3 & 4)
        double semitones_from_A4 = ((double) X + (double) Y) - (double) A4SEMITONES;
        double exponential = semitones_from_A4 / 12.0;
        int frequency = round(pow(2.0, exponential) * 440.0);
        return (frequency);

    } else {
        printf("Error in frequency() - must pass in 2 or 3 character string for note\n");
        return -1;
    }
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

// returns the index in the array
// implements basic linear search
int find_in_array(char *findthis, char *inthis[], int length_of_in_this) {
    
    // printf("findthis: %s\n", findthis);

    for (int i = 0; i < length_of_in_this; i++) {
        // printf("inthis[%d] = %s\n", i, inthis[i]);
        if (strcmp(findthis, inthis[i]) == 0) {
            // printf("MATCH: %s = %s at index %d\n", findthis, inthis[i], i);
            return i;
        }
    }
    return -1;
}


