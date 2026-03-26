#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <inttypes.h>

void d2b(unsigned int value);
int toggle(unsigned int value,unsigned int pos);
void wait_user();
int main()
{
	int value,pos;
	printf("Enter the 8 bit register value: \n");
	scanf("%u",&value);
	printf("The 8 bit register value before toggle : \n");
	d2b(value);
	printf("\nEnter the  bit position to toggle: \n");
	scanf("%u",&pos);
	int result = toggle(value,pos);
	printf("\nThe 8 bit register value After toggle : \n");
	d2b(result);
	printf("\nThe result after Toggle the bit: %u",result);
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
int toggle(unsigned int value,unsigned int pos)
{
	value ^=(1U<<pos);
	return value;
}
void wait_user()
{
	printf("\nPress Enter to Exit: ");
	while(getchar()!='\n');
	getchar();
}
