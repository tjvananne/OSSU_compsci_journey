
# Week 2 progress

## Gaining Comfort With:

* compiling
    - creating .o objects with gcc -c
    - creating output executables with -o
    - creating .a libraries with ar rcs [.o files] 
    - linking libraries while compiling `gcc -o executable code.c -lcs50 -lm`
* debugging in codeblocks
* vim
* functions
* basic data types
    - converting ints to chars and vice versa (I've never spent so much time looking at the ASCII table)
    - printf, sprintf (still need to learn more about fprintf or whatever the error one is)
    - placeholders that go into printf (%d, %f, %i, %s, etc.)
* what strings are and how they terminate with null bytes '\0'


## Still Confused By:

* make files - I'd like to learn more about this. Seems like CS50 uses mainly Clang while I'm using gcc, that might be a problem?
* pointers - specifically passing arrays into functions
    - current understanding: function parameters are always passed by value (I think?) so if you pass in the pointers of the array... then you can actually mimic pass-by-reference instead of creating a copy of the value?
    - I ran into a lot of issues where the compiler yelled that it expected `char *` but I provided `char **` so I think I got a little too asterisk happy. In retrospect, it seemed like the asterisks were only required for the parameter definition of the array to be passed in (or array of it's pointers rather) and NOT on the actual argument being passed in. 
* What all goes in header files and what goes into libraries...
    - string.h provides new data types? how is that? are they structs? what is a struct? can I do that with my own header files?
* Structuring large projects - this will come with time I assume, but I'd like to gain a better understanding of how to structure large projects in C. How to properly manage complexity through functions, files, etc.


## Overall Sentiment:

I was so excited/relieved to hear that stupid little C scale when I successfully compiled the notes.c program.


