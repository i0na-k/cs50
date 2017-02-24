#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string s = GetString();
    int i = 0;
    {
        printf ("%c", toupper (s[0]));
    }
    
        for ( i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ')
            {
                printf ("%c", toupper (s[i + 1]));
            }
        }

    {
         printf ("\n");
    }
    
}
