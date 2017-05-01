/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
 
typedef unsigned char BYTE;
char jpgName[8];
 
int main()
{
    // open card file
    FILE * file = fopen("card.raw","rw");
    if (file == NULL)
    {
    printf("Could not open 'card.raw'");
    return 2;
    }
   
    BYTE buffer[512];
    int jpegCount = 000;
    FILE * image = NULL;
   
    // continue this whilst !EOF
    while(fread(&buffer, sizeof(buffer), 1, file) > 0)
    {
            // find beginning of JPEG
           
           
            if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
            {
                if (jpegCount > 000)
                    {
                       
                        fclose(image);
                    }
                       
                       
 
           
           
               
             
                 
           
                    // open new JPEG then continue to write 512 bytes until new JPEG is found
                    sprintf(jpgName,"%03d.jpg", jpegCount);
 
                       
                    // then open the result of sprintf using fopen()
                    image = fopen(jpgName, "w");
                    // JPEG is opened
                    jpegCount++;
                   
                    fwrite(&buffer,sizeof(buffer),1,image);
                   
 
               
            }
           
        }
       
           
    fclose(file);
    return 0;
}
