#include <stdio.h>
#include <stdlib.h>


#define VERBOSE 1
#define MAXLENGTH 1000


int main(int argc, char *argv[])
{

    int ckey;

    // if passed in key, assign it, otherwise just return
    if (argc == 2) {
        printf("The ckey is: %s\n", argv[1]);

        int i = 0;
        int arg_character = 0;
        while ((arg_character = argv[1][i]) != '\0') {
            if(arg_character < '0' || arg_character > '9') {
                printf("Make sure the argument is an integer\n");
                return(1);
            }
            i++;
        }

        ckey = atoi(argv[1]);
    } else {
        printf("Need to pass in key as argument\n");
        return(1);
    }


    char plaintext[MAXLENGTH];

    // find length of plaintext input
    int plaintext_length = 0; // acts as length and index of plaintext char string
    int c = 0;
    printf("plaintext: ");
    while ((c = getchar()) != EOF && plaintext_length < MAXLENGTH) {
        plaintext[plaintext_length] = c;
        plaintext_length++;
    }
    

    if (VERBOSE) { printf("\nplaintext_length: %d\n", plaintext_length); }


    // implement the cipher
    char ciphertext[plaintext_length];
    for( int i = 0; i < plaintext_length; i++ ) {
        
        // cipher for lowercase
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
           ciphertext[i] = (((plaintext[i] - 'a' + ckey) % 26) + 'a');

        // cipher for uppercase
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (((plaintext[i] - 'A' + ckey) % 26) + 'A');

        // not a character, just pass through
        } else {
            ciphertext[i] = plaintext[i];
        }
    }


    // print out cipher text
    for (int i = 0; i < plaintext_length; i++) {
        if (i == 0) {printf("\nCipher Text: "); }
        printf("%c", ciphertext[i]);   
    }
    printf("\n");
}



