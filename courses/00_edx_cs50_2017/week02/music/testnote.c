#include <stdio.h>

#define VERBOSE 1

int main(void) 
{
    
    char *notes_sharp[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E",
                           "F", "F#", "G", "G#"}

    char *notes_flat[] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E",
                          "F", "Gb", "G", "Ab"}


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
        int X = userinput[0] - 'A';
        printf("X is now: %d\n", X);
        int Y = (userinput[1] - '0') * 12;
        printf("Y is now: %d\n", Y);
        printf("Semitones: %d\n", (X + Y));

    // process if three characters (X#Y)
    } else if (userinput_length == 3) {
        int X = userinput[0] - 'A';
        if (userinput[1] == '#') {
            X++;
        } else if (userinput[1] == 'b') {
            X--;
        } else {
            printf("Second character should be 'b' or '#'\n");
            return 1;
        }
        int Y = (userinput[1] - '0') * 12;
        printf("Semitones: %d\n", (X + Y));

    } else {
        printf("We've got a problem\n");
    }
    
}
