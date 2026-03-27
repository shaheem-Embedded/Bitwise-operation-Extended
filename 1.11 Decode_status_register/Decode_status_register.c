#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

char *flags[8] = {"POWER ON","POWER OFF","TX","RX","UART ON","UART OFF","SPI ON","SPI OFF"};
void d2b(unsigned int value);
void status(unsigned int reg);
void wait_user();

int main()
{
	int reg;
	printf("Enter 8 bit register\n");
	scanf("%d",&reg);
	printf("Entered 8 bit register is : ");
	d2b(reg);
	printf("STATUS DECODED AS BELOW : \n");
	status(reg);
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
void status(unsigned int reg)
{
	for(int i=0;i<8;i++)
	{
		if(reg&(1u<<i))
		{
			printf("%s",*(flags+i));
			printf("\n");
		}
		else
		{
			;
		}
	}
}

void wait_user()
{
	while(getchar()!='\n');
	printf("Press Enter to Exit...!");
	getchar();
}
