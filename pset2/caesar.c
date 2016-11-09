#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf ("usage : ./caesar + key \n");
		return 1;
	}
	

	int k = atoi(argv[1]);

	string t = GetString(); 


	int i;

	for (i = 0; i < strlen(t); i++)
		
	{   
		char c = t[i];
		if (!isalpha(c))
		{
			printf("%c",c);
		}
		
		if (isalpha(c))
		{
			if (isupper(c))
			{
				printf ("%c",((c - 65) + k) % 26 + 65);
			}
			
			if (islower(c))
			{
				printf ("%c", ((c - 97) + k) % 26 + 97);
			}
			
			
			
			
		}
	}
	printf("\n");

}
