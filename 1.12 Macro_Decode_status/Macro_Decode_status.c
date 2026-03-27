#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define BIT0 (1u<<0)
#define BIT1 (1u<<1)
#define BIT2 (1u<<2)
#define BIT3 (1u<<3)
#define BIT4 (1u<<4)
#define BIT5 (1u<<5)
#define BIT6 (1u<<6)
#define BIT7 (1u<<7)

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
	if (reg & BIT0) printf("POWER ON\n");
	if (reg & BIT1) printf("POWER OFF\n");
	if (reg & BIT2) printf("TX\n");
	if (reg & BIT3) printf("RX\n");
	if (reg & BIT4) printf("UART ON\n");
	if (reg & BIT5) printf("UART OFF\n");
	if (reg & BIT6) printf("SPI ON\n");
	if (reg & BIT7) printf("SPI OFF\n");
}
void wait_user()
{
	while(getchar()!='\n');
	printf("Press Enter to Exit...!");
	getchar();
}
