#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("how many minutes do you usually take a shower for?");
    int n = GetInt();
    printf("you use %i bottles of water when you shower", n * 12);
}
