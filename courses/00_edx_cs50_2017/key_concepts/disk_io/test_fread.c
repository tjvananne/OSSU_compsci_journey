#include <stdio.h>
#include <string.h>

int main(void) 
{

    printf("testing fread and fwrite\n");
    
        // initialize a FILE pointer:
    FILE *fp;
    
    // initialize a string (strings are just pointers to first character in the string)
    char* mystr = "This is my string";

    printf("length of mystring: %zd\n", strlen(mystr));
    


    // fopen:
    // FILE *fopen(const char *filename, const char *mode)
    // filename: this is the C string containing the name of the file to be opened
    // mode: r (read), w (write), a (append), r+ (r and w - file must exist), 
    // w+ (r and w - creates the file), a+ (opens file for reading and appending)    

    // open a connection to a file on disk
    fp = fopen( "file.txt", "w");
        



    // fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    // ptr: the pointer to the array of elements to be written
    // size: the size in bytes of each element to be written
    // nmemb: the number of elements, each one with a size of <size> bytes
    // stream: the pointer to a FILE object that specifies an output stream

    // now use fwrite to write these 
    printf("sizeof(mystring): i%\n", sizeof(mystr));
    fwrite(mystr, 1, sizeof(mystr), fp);

    // remember to close the connection
    fclose(fp);
    return(0);


}
