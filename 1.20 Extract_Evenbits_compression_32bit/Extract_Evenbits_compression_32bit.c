#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int Even_bits_compression(int reg);

int d2b32(int reg);
void wait_user();
int main()
{
int reg;
printf("Enter the 32 bit register : \n");
scanf("%d",&reg);
printf("\nRegister value in Binary as :\n");
d2b32(reg);

int result = Even_bits_compression(reg);

printf("\nRegister value after Bit compression as : %u\n",result);
printf("\nRegister value after Bit compression as in Binary as : \n");
d2b32(result);
wait_user();
return 0;

}

int d2b32(int reg)
{
	for(int i=31;i>=0;i--)
	{
		if((reg>>i) & (1U))
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}


int Even_bits_compression(int reg)
{
	uint16_t out;uint16_t pos=0;
	for(int i=0;i<32;i=i+2)
	{
     if((reg>>i)&1U)
     {
    	 out |= 1U<<pos;
     }
     else
     {
    	 out &= ~(1U<<pos);
     }
	 pos++;
	}
	return out;
}


void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}

