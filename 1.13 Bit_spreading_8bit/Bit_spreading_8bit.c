#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

uint8_t reg;
int d2b8(uint8_t reg);
int d2b16(uint16_t res_reg);
int bit_spreading(uint8_t reg);
void wait_user();
int main()
{
printf("Enter the 8 bit register : \n");
scanf("%d",&reg);
printf("Register value in Binary as : \n");
d2b8(reg);
uint16_t res_reg = bit_spreading(reg);
printf("\nResultant Register value with Bit spreading with 0 as : %d \n",res_reg);
printf("\nResultant Register value with Bit spreading with 0 in Binary as : \n");
d2b16(res_reg);
wait_user();
return 0;
}

int d2b8(uint8_t reg)
{
	for(uint8_t i=8;i>0;i--)
	{
		if((reg>>i) & (1U))
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}
int d2b16(uint16_t res_reg)
{
	for(uint16_t i=16;i>0;i--)
	{
		if((res_reg>>i) & (1U))
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}
int bit_spreading(uint8_t reg)
{
	uint16_t res_reg=0x0000;
	int j=0;
	for(int i=0;i<8;i++)
	{
		uint8_t bit = (reg >> i)&1U;
		res_reg |= bit<<j;
		j= j+2;
	}
	return res_reg;
}
void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();

}

