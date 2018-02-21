#include <stdio.h>
#include <string.h>

#define VERBOSE 0



int find_in_array(char *findthis, char *inthis[], int length_of_in_this);

int main(void) 
{
    
    char *notes[17] = {"A", "A#", "Bb", "B", "C", "C#", "Db", "D", "D#", "Eb", "E", "F",
                     "F#", "Gb", "G", "G#", "Ab"};

    int note_vals[17] = {0, 1, 1, 2, 3, 4, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 11};

    if (VERBOSE) { 
        printf("Notes: \n");
        for (int i = 0; i < 17; i++) {
            printf("Note: %s with value of %d\n", notes[i], note_vals[i]);
        }
    }


    printf("enter string in format X#Y or XY\n");
    char userinput[3];
    int userinput_length = 0;

    // capture user input
    int c;
    while ((c = getchar()) != EOF && userinput_length <= 3) {
        userinput[userinput_length] = c;
        userinput_length++;
    }

    // process if two characters (XY)    
    if (userinput_length == 2) {
        
        // manually construct a string of the music note
        char input_note[2];
        input_note[0] = userinput[0];
        input_note[1] = '\0';

        //int X = userinput[0] - 'A';
        int X = note_vals[find_in_array(input_note, notes, 17)];
        printf("X is now: %d\n", X);
        int Y = (userinput[1] - '0') * 12;
        printf("Y is now: %d\n", Y);
        printf("Semitones: %d\n", (X + Y));

    // process if three characters (X#Y)
    } else if (userinput_length == 3) {

        // manually construct a string of the music note
        char input_note[3];
        input_note[0] = userinput[0];
        input_note[1] = userinput[1];
        input_note[2] = '\0';

        // int X = userinput[0] - 'A';
        
        /*
        if (userinput[1] == '#') {
            X++;
        } else if (userinput[1] == 'b') {
            X--;
        } else {
            printf("Second character should be 'b' or '#'\n");
            return 1;
        }
        */
        int X = note_vals[find_in_array(input_note, notes, 17)];
        int Y = (userinput[2] - '0') * 12;
        printf("Semitones: %d\n", (X + Y));

    } else {
        printf("We've got a problem\n");
    }
    
} // end of main()


// returns the index in the array
// implements basic linear search
int find_in_array(char *findthis, char *inthis[], int length_of_in_this) {
    
    printf("findthis: %s\n", findthis);

    for (int i = 0; i < length_of_in_this; i++) {
        printf("inthis[%d] = %s\n", i, inthis[i]);
        if (strcmp(findthis, inthis[i]) == 0) {
            printf("MATCH: %s = %s at index %d\n", findthis, inthis[i], i);
            return i;
        }
    }

}




