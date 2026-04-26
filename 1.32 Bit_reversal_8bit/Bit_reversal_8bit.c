#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int d2b(int value);
int bit_reversal(int value);
void wait_user();

int main()
{
int value;
printf("Enter the value: \n");
scanf("%d",&value);

printf("\nEntered value in Binary as: \n");
d2b(value);

int result = bit_reversal(value);
printf("\nBit reversed value is: %d\n",result);
printf("\nBit reversed value in Binary as: \n");
d2b(result);
wait_user();
}

int d2b(int value)
{
	for(int i=31;i>=0;i--)
	{
		if(((value>>i))&1U)
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}

int bit_reversal(int value)
{
int result =0;
for(int i=0;i<8;i++)
{
result<<=1;
result |= (value&1u);
value>>=1;
}
return result;
}

void wait_user()
{
	while(getchar()!='\n');
	printf("\nPRESS ENTER TO EXIT...");
	getchar();
}
