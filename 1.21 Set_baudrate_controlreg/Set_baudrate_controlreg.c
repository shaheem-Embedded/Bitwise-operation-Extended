#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int Set_Baud(int reg,int pos,int len,int val);

int d2b32(int reg);
void wait_user();
int main()
{
int reg,pos,len,val;
printf("Enter the 32 bit register : \n");
scanf("%d",&reg);
printf("\nRegister value in Binary as :\n");
d2b32(reg);
printf("\nEnter the Position to set the Baud rate\n");
scanf("%d",&pos);
printf("\nEnter the length to set the Baud rate\n");
scanf("%d",&len);
printf("\nEnter the Baud rate value to set in the selected Position\n");
scanf("%d",&val);

int result = Set_Baud(reg,pos,len,val);

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

int Set_Baud(int reg,int pos,int len,int val)
{
int mask =0;
mask = ((1U<<len)-1)<<pos;
reg &=~(mask);
reg|=(val<<pos);
return reg;
}


void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}

