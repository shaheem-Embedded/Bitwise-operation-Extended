#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <inttypes.h>

void d2b(unsigned int value);
int check(unsigned int value);
void wait_user();
int main()
{
	int value;
	printf("Enter the 16 bit register value: ");
	scanf("%u",&value);
	printf("\nEntered 16 bit register value is  : ");
	d2b(value);
	int result = check(value);
	printf("\nThe register value with highest set bit is %d: \n",result);
    d2b(result);
	wait_user();
    return (0);
}

void d2b(unsigned int value)
{
	for(int i=15;i>=0;i--)
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
int check(unsigned int value)
{
	int mask =0x00;

	for(int i=15;i>=0;i--)
	{
     mask = (1U<<i);
     if(mask&value)
     {
    	 return mask;
     }
     else
     {
    	 ;
     }
}
	 return 0;
}
void wait_user()
{
	printf("\nPress Enter to Exit: ");
	while(getchar()!='\n');
	getchar();
}
