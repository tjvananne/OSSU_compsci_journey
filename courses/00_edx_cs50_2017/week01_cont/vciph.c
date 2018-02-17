#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXINPUTSIZE 1000
#define VERBOSE 0 

int main(int argc, char *argv[]) 
{
    // verify the number of args
    if (argc != 2) {
        printf("must supply exactly one argument\n");
        return(1);
    }

    // make sure arg is only made of characters
    int arg_char = 0;
    int arg_indx = 0;
    while ((arg_char = argv[1][arg_indx]) != '\0') {
        if (VERBOSE) printf("arg_char: %c\n", arg_char);
        if (!isalpha(arg_char)) {
            printf("argument must be made up of only characters\n");
            return(1);
        }
        arg_indx++;
    }

    // extract the key for how much to shift
    int arg_len = arg_indx;
    if (VERBOSE) printf("arg_len: %d\n", arg_len);

    int key[arg_len];
    int i;
    if (VERBOSE) printf("shift key: ");
    for (i = 0; i < arg_len; i++) {
        if (islower(argv[1][i])) {
            key[i] = argv[1][i] - 'a';
        } else {
            key[i] = argv[1][i] - 'A';
        }        
        if (VERBOSE) printf(" %d ", key[i]);
    }
    if (VERBOSE) printf("\n");   
    if(VERBOSE) printf("arg_len: %d\n", arg_len);

    
    // initialize plaintext to maxlength (is this really the best way?)
    char plaintext[MAXINPUTSIZE];    


    // find the length of plaintext message
    int plaintext_length = 0;
    int c;
    printf("plaintext: ");
    while ((c = getchar()) != EOF && plaintext_length < MAXINPUTSIZE) {
        if (VERBOSE) printf("value of character: %c\n", c); 
        plaintext[plaintext_length] = c;
        plaintext_length++;
    } 


    // checkpoint, make sure we're collecting the input correctly    
    if (VERBOSE) {
        printf("\nplaintext: ");
        for (i = 0; i < plaintext_length; i++) {
            printf("%c", plaintext[i]);
        }
        printf("\n");
    }


    // initialize the cipher text
    char ciphertext[plaintext_length];
    int key_i = 0;  // key index
    for (i = 0; i < plaintext_length; i++) {
        if (VERBOSE) printf("now processing this character: %c\n", plaintext[i]);
        // i is the index of the plain text
        // key_i is the index of the key which needs modulo if it goes beyone

        // check if key_i needs to wrap itself
        if (key_i == arg_len) {
            key_i = key_i % arg_len;
        }

        if (VERBOSE) {
            printf("key_i: %d\n", key_i);
            printf("key[key_i]: %d\n", key[key_i]);
        }
        

        // if this character is alpha, then apply the key shift
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i])) {
                ciphertext[i] = (((plaintext[i] - 'a') + key[key_i]) % 26) + 'a';
                if (VERBOSE) printf("processed char: %c\n", ciphertext[i]);
            } else {
                ciphertext[i] = (((plaintext[i] - 'A') + key[key_i]) % 26) + 'A';
                if (VERBOSE) printf("processed char: %c\n", ciphertext[i]);
            }
            key_i++;  // only increment key index if it's used
        } else {
            ciphertext[i] = plaintext[i];
            if (VERBOSE) printf("processed char: %c\n", ciphertext[i]);
        }

    }


    // report out the cipher text
    printf("ciphertext: ");
    for (i = 0; i < plaintext_length; i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

}


