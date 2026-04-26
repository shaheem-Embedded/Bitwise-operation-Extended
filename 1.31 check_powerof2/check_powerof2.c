#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int d2b(int value);
char* power_check(int value);
void wait_user();

int main()
{
int value;
printf("Enter the value: \n");
scanf("%d",&value);

printf("\nEntered value in Binary as: \n");
d2b(value);

char* result = power_check(value);
printf("%s",result);
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

char* power_check(int value)
{
for(int i=0;i<32;i++)
{
if(!(value & (1u<<i)))
{
	return "\nValue is power of 2";
}
else
{
	return "\nValue is NOT a power of 2";
}
}
return 0;
}

void wait_user()
{
	while(getchar()!='\n');
	printf("\nPRESS ENTER TO EXIT...");
	getchar();
}
