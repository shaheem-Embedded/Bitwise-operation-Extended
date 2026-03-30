#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define ENABLE(reg,enable)      (reg |= (enable<<0))
#define MODE(reg,mode)          (reg |= (mode<<1))
#define SPEED(reg,speed)        (reg |= (speed<<3))
#define RESERVED(reg)           (reg &=~((1U<<6)|(1U<<7)))

uint8_t reg;
int d2b8(uint8_t reg);
int enable_macro_config(int reg,int ENABLE,int MODE,int SPEED);
void wait_user();
int main()
{
int ENABLE,MODE,SPEED;

printf("Enter the 8 bit register : \n");
scanf("%d",&reg);
printf("\nRegister value in Binary as : \n");
d2b8(reg);
printf("\nEnter ENABLE value : \n");
scanf("%d",&ENABLE);
printf("\nEnter MODE value : \n");
scanf("%d",&MODE);
printf("\nEnter SPEED value : \n");
scanf("%d",&SPEED);


int result = enable_macro_config(reg,ENABLE,MODE,SPEED);

printf("\nResultant Register value with Macro enabled : %d \n",result);
printf("\nResultant Register value with Bit spreading with 0 in Binary as : \n");
d2b8(result);

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

int enable_macro_config(int reg,int ENABLE,int MODE,int SPEED)
{
	ENABLE(reg,ENABLE);
	MODE(reg,MODE);
	SPEED(reg,SPEED);
	RESERVED(reg);
	return reg;
}

void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();

}

