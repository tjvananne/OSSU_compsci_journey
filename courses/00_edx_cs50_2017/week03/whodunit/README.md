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


**0x42 0x4D** which is 66 and 77 in decimal respectively.

* https://en.wikipedia.org/wiki/BMP_file_format
* https://www.rapidtables.com/convert/number/hex-to-decimal.html

Keep in mind, a single character of hexadecimal represents 4 bits, so two characters of hex will be an entire byte (8 bits).




## What's the difference between `bfSize` and `biSize`?

* **bfSize**: the entire size of the bitmap file
* **biSize**: the size of the header of the bitmap in bytes (pro-tip, this is always 40 bytes)


## What does it mean if `biHeight` is negative?

https://msdn.microsoft.com/en-us/library/windows/desktop/dd318229(v=vs.85).aspx

* **biHeight**: if it's positive, then the bitmap is a bottom-up bitmap with the origin in the lower left pixel. If it's negative, then the bitmap is a top-down bitmap with the origin in the upper left pixel.


## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

**biBitCount** specifies the number of bits per pixel (color depth).



## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

There are many reasons why fopen could return NULL: https://stackoverflow.com/questions/5987626/why-does-fopen-return-a-null-pointer

* file doesn't exist
* incorrect permissions
* network is down and the path requires access to the network
* current directory of the process is different than you expect, so the relative path to the file is wrong
* file is opened in a mode that doesn't allow other accesses



## Why is the third argument to `fread` always `1` in our code?

fread takes in four arguments:

1. the pointer to the address in memory to store the thing we're reading in
2. the size of the elements to be read into memory
3. the **number of elements** being read into memory
4. the pointer to a FILE object to read into memory (from disk I take it?)


In our code, #2 above is the size of the bitmap file header. So the **number of elements** we need to read in is only 1, because we're only reading in a single bitmap header file at a time. 



## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

First, bi.biWidth is the width of the bitmap in pixels. So this would mean that our image is 3 pixels wide. If we multiply that by the number of bytes per RGBTRIPLE (pixel), that gives us 9 bytes. We need that to be a multiple of four (because of reasons inside of scanf and mathematical reasons we won't get into). In order to make that a value divisible by four, we would need to add 3 bytes of padding (zeroes). So hopefully, going through that exercise by hand will give us a value of 3. 


The line of code in questions is this:


    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


RGBTRIPLE consists of three bytes, so the sizeof() function will return a value of 3. bi.biWidth * 3 will be 3 * 3 which is = 9. That gives us:

	(4 - (9) % 4) % 4
	
	
modulo comes before subtraction, so that should give us:

	
	(4 - 1) % 4
	
	
which then evaluates to:


	3 % 4
	
	
and finally:


	3
	

	

## What does `fseek` do?

TODO

## What is `SEEK_CUR`?

TODO
