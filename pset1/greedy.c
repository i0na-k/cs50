#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	double f;
	
	do
	{
		printf("how much change is used?\n");
		f = GetFloat();
	}
	while(f < 0.0f);


	int cent_amount = round(f * 100);


	int count = 0;
	count = round(count * 100);
	int quarter_t = cent_amount / 25; 
	int dime_t = cent_amount / 10; 
	int nickel_t = cent_amount / 5; 
	int penny_t = cent_amount / 1;
	
	while(cent_amount >= 25)
	{
		quarter_t = cent_amount / 25;
		cent_amount = cent_amount - quarter_t * 25;
		count = count + quarter_t;
	}
	
	while(cent_amount >= 10)
	{
		dime_t = cent_amount / 10;
		cent_amount = cent_amount - dime_t * 10;
		count = count + dime_t;
	}

	while(cent_amount >= 5)
	{
		nickel_t = cent_amount / 5;
		cent_amount = cent_amount - nickel_t * 5;
		count = count + nickel_t;
	}

	while(cent_amount >= 1)
	{
		penny_t = cent_amount / 1;
		cent_amount = cent_amount - penny_t * 1;
		count = count + penny_t;
	}

	{
		printf("%d\n", count);
	}

	
}
