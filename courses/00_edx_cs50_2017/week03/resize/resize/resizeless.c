// Copies a BMP file


/*
this is my less comfortable file.
I just got done figuring out how to accept a character array from the user inside the first command-line argument and
convert that to an integer with sscanf. I'm also checking if it is less than or equal to a length of 3, since the max 
integer value we're accepting is 100. I should next check to make sure the integer is actually less than 100.

Next steps are:
1) figure out what all needs to change in the output files bitmap header bitmap info structs
2) make changes for horizontal scaling, including determining the output file per-row padding value
3) implement a vertical scaling method whether we use the write-again or copy method
	- basically, should we save an array of the RGBTRIPLE structs we created horizontally as an array and then write them n number of times?

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage - must have three arguments
    if (argc != 4)  
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // process the arguments
	char *resize_factor_array = argv[1];  // this is really an integer, but read it in as character array to begin with
    char *infile = argv[2];
    char *outfile = argv[3];

	
	// resize factor should be between 0 and 100, so make sure character array is less than three digits
	if (strlen(resize_factor_array) > 3) {
		fprintf(stderr, "please input a number greater than 0 and less than 100 for resize factor\n");
		return 1;
	}
	
	// now convert the character array of resize factor into an integer
	// using sscanf for this: https://stackoverflow.com/questions/10204471/convert-char-array-to-a-int-number-in-c 
	int resize_factor;
	sscanf(resize_factor_array, "%d", &resize_factor);  // arg three is the ADDRESS of the integer
	printf("now we have resize factor array as an integer: %d\n", resize_factor);
	
	
	
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
