#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int Set_bits(int reg,int start,int end);

uint8_t reg;
int d2b8(uint8_t reg);
void wait_user();
int main()
{
int reg,end,start;
printf("Enter the 8 bit register : \n");
scanf("%d",&reg);
printf("\nRegister value in Binary as : \n");
d2b8(reg);
printf("\nEnter the start position to SET the bits:\n");
scanf("%d",&start);
printf("\nEnter the End position to SET the bits:\n");
scanf("%d",&end);

int result = Set_bits(reg,start,end);

printf("\nRegister value after Set the Bits in required Positions as : %d\n",result);
printf("\nRegister value after Set the Bits in required Positions in Binary as : \n");
d2b8(result);

wait_user();
return 0;
}

int d2b8(uint8_t reg)
{
	for(int i=7;i>=0;i--)
	{
		if((reg>>i) & (1U))
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}

int Set_bits(int reg,int start,int end)
{
int mask=0;
mask=(1U<<((end-start)+1))-1;
mask<<=start;
reg|=mask;
	  return reg;
}

void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}

