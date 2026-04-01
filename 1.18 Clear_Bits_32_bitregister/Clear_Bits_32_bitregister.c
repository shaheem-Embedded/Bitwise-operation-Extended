#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int Clear_bits(int reg,int start,int length);

int d2b32(int reg);
void wait_user();
int main()
{
int reg,length,start;
printf("Enter the 32 bit register : \n");
scanf("%d",&reg);
printf("\nRegister value in Binary as : \n");
d2b32(reg);
printf("\nEnter the start position to Clear the bits:\n");
scanf("%d",&start);
printf("\nEnter the Length to clear the bits:\n");
scanf("%d",&length);

int result = Clear_bits(reg,start,length);

printf("\nRegister value after Extract the Bits in required Positions as : %d\n",result);
printf("\nRegister value after Extract the Bits in required Positions in Binary as : \n");
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


int Clear_bits(int reg,int start,int length)
{
int mask=0;
mask=((1U<<length)-1)<<start;

reg&= ~(mask);
return reg;
}


void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}

