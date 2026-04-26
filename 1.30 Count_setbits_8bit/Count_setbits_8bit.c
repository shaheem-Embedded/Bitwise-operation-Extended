#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int d2b(int value);
void count_setbit(int value,int *zero,int *one);
void wait_user();

int main()
{
int value;
int one, zero;
printf("Enter the 8 bit register value :\n");
scanf("%d",&value);

printf("\nEntered 8 Register value in Binary as: \n");
d2b(value);
count_setbit(value,&one,&zero);
printf("\nNo of set bits  are %d and No of 0s are %d in 8 bit register value \n",one,zero);
wait_user();
}

int d2b(int value)
{
	for(int i=7;i>=0;i--)
	{
		if(((value>>i))&1U)
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}

void count_setbit(int value,int *zero,int *one)
{
	*one=0;
	*zero=0;
for(int i=0;i<8;i++)
{
if((value>>i)&1U)
{
	(*one)++;
}
else
{
	(*zero)++;
}
}
}

void wait_user()
{
	while(getchar()!='\n');
	printf("\nPRESS ENTER TO EXIT...");
	getchar();
}
