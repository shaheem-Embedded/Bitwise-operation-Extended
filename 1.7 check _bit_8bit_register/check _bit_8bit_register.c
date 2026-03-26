#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <inttypes.h>

void d2b(unsigned int value);
char* check(unsigned int value,unsigned int pos);
void wait_user();
int main()
{
	int value,pos;
	printf("Enter the 8 bit register value: \n");
	scanf("%u",&value);
	printf("The 8 bit register value : \n");
	d2b(value);
	printf("\nEnter the  bit position to check: \n");
	scanf("%u",&pos);
	char* result = check(value,pos);
	printf("\nThe result after checking the bit: %s",result);
	wait_user();
return (0);
}

void d2b(unsigned int value)
{
	for(int i=7;i>=0;i--)
	{
		if((value>>i) & 1U)
		{
			printf("1");
		}
		else
			printf("0");
		if(i ==4)
			printf(" ");
	}
}
char* check(unsigned int value,unsigned int pos)
{
	if(value & (1U<<pos))
	{
		return "Entered bit position is 1";
	}
	return "Entered bit position is 0";
}
void wait_user()
{
	printf("\nPress Enter to Exit: ");
	while(getchar()!='\n');
	getchar();
}
