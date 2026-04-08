/*
 * Count_Setbits.c
 *
 *  Created on: Apr 7, 2026
 *      Author: SHAHEEM
 */

#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>

int d2b(int integer);
int count_setbit(int integer);
void wait_user();

int main()
{
	int integer;
	printf("Enter the integer value : \n");
	scanf("%x",&integer);
	printf("\nInteger value in Binary as: \n");
	d2b(integer);

	int result = count_setbit(integer);
	printf("\nNo of set bits in the integer  is %d: \n",result);

	wait_user();
}

int d2b(int integer)
{
	for(int i=31;i>=0;i--)
	{
		if((integer>>i)&1)
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}
int count_setbit(int integer)
{
	int count=0;
for(int i=31;i>=0;i--)
{
	if((integer>>i)&(1U))
		{
			count++;
		}
}
	return count;
}

void wait_user()
{
	while (getchar()!='\n');
	printf("\nPress Enter to Exit...!");
	getchar();
}



