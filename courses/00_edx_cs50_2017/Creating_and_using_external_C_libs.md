
# Linking manually

Alright, so I've figured this stuff out I think.

## creating a .a archive library

First step you need to do is compile your .c source-code files into .o object files like so (example being used is the cs50.c and cs50.h files I found on their github, since that's what my goal is to use locally anyway).

    gcc -c cs50.c

Now I have a cs50.o file in this directory along with my cs50.h. Next, we'll want to go ahead and create the .a archive file.

    ar rcs libcs50.a cs50.o

You can add as many .o object files after you name the .a file. Also, it is a naming convention that you must use "lib" in front of the name and it has to have a .a file extention. The "rcs" flags are for "replacement", "creation", "index building" respectively. I'm not 100% sure on these, but just keep "rcs" on every time you build an archive file.

## using the .a archive library

So now you've written your dumb mario.c source-code file. At the top of that file, you should have something like this:

    #include <stdio.h>
    #include "cs50.h"
    ...dumb mario code inside main here..



The <> brackets tells the compiler it's a standard library to go look for while compiling. The "" quotes tells the compiler to first look in whatever directory you're using (or that you specify in some flags that are yet to be explained), and then it looks for standard libraries.

Next we'll need to compile the mario.c file into it's object file. We will pretend like the cs50.h file is in the **PARENT DIRECTORY** relative to where our mario.c file is. To clarify, we would have to use `cd ..` to get to where our cs50.h file is.

    gcc -c -I .. mario.c

The "-I .." tells the gcc program where to find our header file. In this case, we're telling it that our header file is in the parent directory "..". This will produce our "mario.o" compiled object file.

Next step is to link the object file to the local archive library with the code we need to create the executable.

    gcc -o mario mario.o -L .. -lcs50

Explanation of this command above:
* **-o mario**     - telling the gcc program what we want the output executable file to be named, in this case "mario"
* **mario.o**      - this is the compiled object file we're attempting to link with the library of executable code we created earlier
* **-L .. -lcs50** - We're wanting to manually link to a file in the parent ("..") directory, that thing we're linking to is called cs50.a but we omit the file extension and add a "-l" to the front of it to show that it is a library file

That produces our output file "mario" that we can then run like so:

    ./mario


## skipping the object file

So I just figured out that you can skip the creation of the object file and go straight to the executable like so.

    gcc -o mario mario.c -I .. -L .. -lcs50

I'm telling the compiler what the output of my executable should be named, what source file to compile (mario.c), where to find the header file I reference in my source file (-I ..), and where to find this library I'm referencing (-L .. -lcs50). Once again, this library is actually named "libcs50.a" in the parent directory, but you omit the "lib" prefix when using the -l flag.


The end!












