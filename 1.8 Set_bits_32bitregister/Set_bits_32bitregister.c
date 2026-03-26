#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <inttypes.h>

void d2b(unsigned int value);
int check(unsigned int value,unsigned int pos,unsigned int len);
void wait_user();
int main()
{
	int value,pos,len;
	printf("Enter the 32 bit register value: ");
	scanf("%u",&value);
	printf("\nEntered 32 bit register value is  : ");
	d2b(value);
	printf("\nEnter the position to start the bits to set : ");
	scanf("%u",&pos);
	printf("\nEnter the length of bits to set: ");
	scanf("%u",&len);
	int result = check(value,pos,len);
	printf("\nThe result after setting the bit starting form position %d and length of %d is %d: \n",pos,len,result);
	printf("Resultant 32 bit register value after setting bits is  : ");
    d2b(result);
	wait_user();
return (0);
}

void d2b(unsigned int value)
{
	for(int i=31;i>=0;i--)
	{
		if((value>>i) & 1U)
		{
			printf("1");
		}
		else
			printf("0");
		if(i%4 ==0)
			printf(" ");
	}
}
int check(unsigned int value,unsigned int pos,unsigned int len)
{
	int mask =0x0000;
	for(int i=0;i<len;i++)
	{
	mask |= (1U<<i);
	}
	mask <<= pos;
	value |= mask;
	return value;
}
void wait_user()
{
	printf("\nPress Enter to Exit: ");
	while(getchar()!='\n');
	getchar();
}
