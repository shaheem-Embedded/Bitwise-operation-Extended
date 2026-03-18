#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int operation(int val);
void wait_user();
void d2b(int val);
void clear_buffer();
int main()
{
	int val;
printf("Enter the Register value:");
scanf("%u",&val);
printf("\nEntered Reg value in decimal is : %u",val);
printf("\nEntered Reg value in binary is :");
d2b(val);
val=operation(val);
printf("\nThe result is: %u",val);
printf("\nReg value in binary after operation is :");
d2b(val);
wait_user();
return 0;
}

int operation(int val)
{
	val ^= (1<<5);
	return val;
}
void wait_user()
{
	while(getchar()!='\n');
	printf("\nPress Enter to Exit");
	getchar();
}
void d2b(int b_val)
{
	for(int i=7;i>=0;i--)
	{
	if((b_val>>i)&1)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	}
}
