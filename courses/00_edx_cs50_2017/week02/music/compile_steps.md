
# Compiling notes.c and synthesize.c

ok so I couldn't get make to work locally even after installing clang.

I added cs50.c and cs50.h into this local directory.

I've been able to compile wav.c with:

    gcc -c wav.c -I .

I can also compile helpers.c with:

    gcc -c helpers.c -I .

and finally cs50:

    gcc -c cs50.c -I .

then I create the library for music:

    ar rcs libmusic.a cs50.o helpers.o wav.o

and finally compile notes.c:

    gcc -o notes notes.c -I . -L . -lmusic -lm

Note that you still need to add the link to the math library.

We can do the same for synthesize:

    gcc -o synthesize synthesize.c -I . -L . -lmusic -lm

Note that these will just create the .wav files. You'll have to be in an OS that supports the playing of .wav files. For example, I am developing in a VirtualBox Ubuntu instance but on my host Windows PC. The directory I'm working on in my guest Ubuntu OS is shared with my host Windows OS, so I can simply double click the output .wav files in windows to listen to them.


