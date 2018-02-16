#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERBOSE 1

int main(int argc, char *argv[])
{
    printf("Plain text: %s\n", argv[1]);

    int cipher_key = 3;
    int plain_str_length = 0;
    printf("argc value: %d\n", argc);
    printf("argv value: %s\n", argv[0]);

    printf("strlen of first arg: %d\n", strlen(argv[1]));

    // so this fails, but that doesn't matter I guess as long as strlen is working
    int i = 0;
    while (argv[1][i] != '\0') {
        plain_str_length++;
        i++;
    }

    if (VERBOSE) { printf("plain_str_length: %d\n", plain_str_length);}

    char cipher_text[plain_str_length];

    if (VERBOSE) {
        for (int i = 0; i < plain_str_length; i++) {
            printf("%c", cipher_text[i]);
        }
    }


    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        printf("%c\n", argv[1][i]);

        if (argv[1][i] >= 'a' && argv[1][i] <= 'z') {
            // cipher for lowercase
            printf("%c", (argv[1][i] + cipher_key) % 'a');

        } else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') {
            // cipher for upper case
            printf("%c", (argv[1][i] + cipher_key) % 'A');


        } else {
            // just pass everything else along as is
            printf("%c", argv[1][i]);
        }


    }






    return 0;
}
