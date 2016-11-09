#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("enter a valid key\n");
        return 1;
    }
        
        
    string k = (argv[1]);
    // checks to see if key is alphanumeric
    for (int c = 0; c < strlen(k); c++)
    {
        if (!isalpha (k[c]))
        {
            printf("enter a valid key\n");
            return 1;
    }
    }

    // obtain plaintext
    string p = GetString();
    int count = 0;
    
    // starts obtaininig value of each char in plaintext
    for ( int j = 0; j < strlen(p); j++)
    {
        int keyValue = (toupper(k[count]) - 'A');
        if (!isalpha(p[j]))
        {
            printf ("%c", p[j]);
        }

        if (isupper(p[j]))
        {
            if (count < strlen(k) - 1)
            {
                count++;
        }
        else
            {
                count = 0;
            }
            printf("%c", ((p[j] - 'A' + keyValue) % 26) + 'A');
        }
            
        else if (islower(p[j]))
        {	
            if (count < strlen(k) - 1)
            {
                count++;
                }
            else
            {
                count = 0;
            }
        
        
            printf("%c", ((p[j] - 'a' + keyValue) % 26) + 'a');
            }
    }
    printf("\n");

}
