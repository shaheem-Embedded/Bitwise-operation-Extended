#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int operation(int val,int pos,int mode);
void wait_user();
void d2b(int val);
int main()
{
	int val,pos,mode;
printf("Enter the Register value,position of the Bit,mode of operation\n"
		"Mode of operation :1 --> Set the Bit position:\n"
		"                  :0 --> Set the Bit position:\n");
scanf("%u,%d,%d",&val,&pos,&mode);
printf("\nEntered Reg value in decimal is : %u",val);
d2b(val);
printf("\nEntered Reg value in binary is :");
operation(val,pos,mode);
printf("\nThe result is: %u",operation(val,pos,mode));
d2b(val);
printf("\nReg value in binary after operation is :");
wait_user();
}

int operation(int val,int pos,int mode)
{
	if(mode == 1)
	{
		val |= 1<<pos;
	}
	if(mode == 0)
	{
		val &= ~(1<<pos);
	}
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
	for(int i=0;1<8;i++)
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
