 /**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
 
int main(int argc, char * argv[]) 
  {
  // ensure proper usage
  if (argc != 4) {
    printf("Usage: ./copy infile outfile\n");
    return 1;
  }
 
  if (atoi(argv[1]) > 100) {
    printf("Please enter number smaller than 100...");
    return 1;
  }
 
 
  // remember filenames
  int n = atoi(argv[1]);
  char * infile = argv[2];
  char * outfile = argv[3];
 
  // open input file
  FILE * inptr = fopen(infile, "r");
  if (inptr == NULL) 
  {
    printf("Could not open %s.\n", infile);
    return 2;
  }
 
  // open output file
  FILE * outptr = fopen(outfile, "w");
  if (outptr == NULL) 
  {
    fclose(inptr);
    fprintf(stderr, "Could not create %s.\n", outfile);
    return 3;
  }
 
  // read infile's BITMAPFILEHEADER
  BITMAPFILEHEADER bf;
  fread( &bf, sizeof(BITMAPFILEHEADER), 1, inptr);
 
  // read infile's BITMAPINFOHEADER
  BITMAPINFOHEADER bi;
  fread( &bi, sizeof(BITMAPINFOHEADER), 1, inptr);
 
  // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
  if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
  bi.biBitCount != 24 || bi.biCompression != 0) 
  {
    fclose(outptr);
    fclose(inptr);
    fprintf(stderr, "Unsupported file format.\n");
    return 4;
  }
 
  // copy these file headers so they can be written to output file
  BITMAPFILEHEADER bfo = bf;
  BITMAPINFOHEADER bio = bi;
 
  // new height and width
  bio.biHeight = bi.biHeight * n;
  bio.biWidth = bi.biWidth * n;
 
  // determine padding for scanlines
  int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
 
  // new padding
  int newpadding = (4 - bio.biWidth * sizeof(RGBTRIPLE) % 4) % 4;
 
  bio.biSizeImage = ((bio.biWidth) * sizeof(RGBTRIPLE) + (newpadding)) * abs(bio.biHeight);
  bfo.bfSize = (bio.biSizeImage) + 54;
 
 
  // write outfile's BITMAPFILEHEADER
  fwrite( &bfo, sizeof(BITMAPFILEHEADER), 1, outptr);
 
  // write outfile's BITMAPINFOHEADER
  fwrite( &bio, sizeof(BITMAPINFOHEADER), 1, outptr);
 
  // iterate over infile's scanlines
 
  // for each scanline in file
  for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
  {
   
     RGBTRIPLE buffer[bio.biWidth];
   
      //for each RGB triple
      for (int j = 0; j < bi.biWidth; j++)
      {
        RGBTRIPLE triple;
     
        // read scanline pixels
        fread( &triple, sizeof(RGBTRIPLE), 1, inptr);
     
        // store n copies of the triple in array
          for (int k = 0; k < n; k++)
          {
            buffer[j * n + k] = triple;
          }
      }
       
        for (int a = 0 ; a < n; a++)
        {
       
          for (int x = 0; x < bio.biWidth; x++)
            {
              fwrite(&buffer[x], sizeof(RGBTRIPLE), 1, outptr);
            }
         
         
        
          // then add it back as new padding (to demonstrate how)
          for (int k = 0; k < newpadding; k++) {
          fputc(0x00, outptr);
        }
       
    }
     //skip original padding
      fseek(inptr, padding, SEEK_CUR);
 
  }
 
       
 
 
  // close infile
  fclose(inptr);
 
  // close outfile
  fclose(outptr);
 
 
  // that's all folks
  return 0;
}
