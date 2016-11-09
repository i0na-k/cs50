#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    
       
    do
    {
        printf("give Mario a number:");
        height = GetInt();
    }
        while(height < 0 || height > 23);
   
   
   
 
    for (int i = 0; i < height; i++) 
    {
         
       
        
         
        for (int s = height - 1; s >= i + 1; s--) 
        {
            printf (" ");
        }
        
        
        for (int k = 0; k <= i + 1; k++)
        {
            printf("#");
        } 
        
        printf("\n");
    
        
         
         
    
    }
}
