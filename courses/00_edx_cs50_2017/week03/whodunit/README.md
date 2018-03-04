# Questions

## What's `stdint.h`?

stdint.h contains different implementations of integers with various "widths". By "width," I'm referring to the number of bits (in binary) required to store each specific type of integer. 


## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

First off, let's breakdown what each little piece of these names of integer types really mean. This was confusing to me at first:

* "u" or not a "u" - this means "unsigned" or "signed" respectively. "unsigned" means that you can represent values from 0 up to the maximum amount that can be represented by that number of bits being all "1's". Unsigned means that 0 is basically the midpoint for what can be represented, because you have equal number of negative digits as you have positive digits that can be respresented.
* "int" - ok.. this just means we're talking about integers
* "8" / "16" / "32" - this is the "width" in the number of bits - 8-bits, 16-bits, 32-bits, etc.
* "_t" - this just indicates that what we're referring to is a type, so don't end variable/function names with "_t" because that will be misleading


A *char* type is of type int, but it represents the smallest block of memory available for assignment. This is generally a byte (8 bits). So while there are some small differences that I don't quite understand yet, *char* is very similar to *uint8_t*. This is architecture/compiler dependent? It might be more correct to say that *unsigned char* is similar to *uint8_t*. 

**Ultimately, the purpose of using these different types is to have cross-architecture fixed width integer types that will behave similarly in all environments
**. If you didn't use these fixed-width integer types, you could run into some unexpected overflow behaviors on different architectures.


This is a helpful resources:

* https://en.wikipedia.org/wiki/C_data_types
* https://stackoverflow.com/questions/231760/what-does-a-type-followed-by-t-underscore-t-represent


## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

* BYTE: 8-bits (unsigned)
* DWORD: 32-bits (unsigned)
* LONG: 32-bits (signed)
* WORD: 16-bits (unsigned)


## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

TODO

## What's the difference between `bfSize` and `biSize`?

TODO

## What does it mean if `biHeight` is negative?

TODO

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

TODO

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

TODO

## Why is the third argument to `fread` always `1` in our code?

TODO

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

TODO

## What is `SEEK_CUR`?

TODO
