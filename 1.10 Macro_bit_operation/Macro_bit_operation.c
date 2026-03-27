#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <inttypes.h>

#define SET_BIT(value,s1,s2) ((value)  |= (1U<<s1)|(1U<<s2))
#define CLEAR_BIT(value,c)   ((value)  &=~(1U<<c))
#define TOGGLE_BIT(value,t)  ((value)  ^= (1U<<t))

int macro_set(unsigned int value,unsigned int s1,unsigned int s2);
int macro(unsigned int value,unsigned int c);
int macro(unsigned int value,unsigned int t);

void d2b(unsigned int value);
void wait_user();

int main()
{
	int value,s1,s2,c,t;
	printf("Enter the 8 bit register value: \n");
	scanf("%u",&value);
	printf("Register value in Binary : \n");
	d2b(value);

	printf("\nEnter the bit positions for the register to SET : \n");
	scanf("%u%u",&s1,&s2);

	printf("Enter the bit positions for the register to CLEAR : \n");
	scanf("%u",&c);

	printf("Enter the bit positions for the register to TOGGLE : \n");
	scanf("%u",&t);

	printf("\nPerform SET BIT  | CLEAR BIT | TOGGLE BIT Operations  : \n");


	value= macro_set(value,s1,s2);
	value= macro_clear(value,c);
	value = macro_toggle(value,t);
	printf("%d: ",value);
	printf("Updated Register Value : \n");
    d2b(value);
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
		if(i%4 ==0)
			printf(" ");
	}
}

int macro_set(unsigned int value,unsigned int s1,unsigned int s2)
{
	SET_BIT(value,s1,s2);
	return value;
}
int macro_clear(unsigned int value,unsigned int c)
{
	CLEAR_BIT(value,c);
	return value;
}
int macro_toggle(unsigned int value,unsigned int t)
{
	CLEAR_BIT(value,t);
	return value;
}


void wait_user()
{
	printf("\nPress Enter to Exit: ");
	while(getchar()!='\n');
	getchar();
}
