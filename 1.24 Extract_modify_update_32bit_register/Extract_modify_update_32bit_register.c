
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

unsigned int data(unsigned int reg,unsigned int mode,unsigned int speed,unsigned int status);
int d2b32(int reg);
int Data(int reg,int len,int pos);
int reg,len,pos;
void wait_user();
int main()
{

printf("Enter the 32 bit register : \n");
scanf("%d",&reg);

printf("32 bit register value in Binary is : \n");
d2b32(reg);

printf("\nEnter the length of bits in register to extract and modify: \n");
scanf("%d",&len);

printf("\nEnter the position of bits in register to extract and modify: \n");
scanf("%d",&pos);


int result = Data(reg,len,pos);
printf("\nResultant 32 bit packed register value is %d\n",result);
printf("\nResultant 32 bit packed register value in binary is %d\n",result);
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

int Data(int reg,int len,int pos)
{
	int mask=0;int out=0;
	int sum=0;
    mask |= (((1U<<len)-1)<<pos);
    out  = (reg & mask);
    out>>=pos;
   /*for(int i=0;i<32;i++)
    {
    	sum += ((out>>i)&1);
    }*/
    if(out<31)
    {
    	out+=1;
    }
    else;

  out <<= pos;
  reg &= ~(mask);
  reg|= out;
  return reg;
}

void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}

