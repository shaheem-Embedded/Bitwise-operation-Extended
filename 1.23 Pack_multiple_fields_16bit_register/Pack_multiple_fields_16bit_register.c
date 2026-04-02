


/*
#include <stdio.h>
#include <stdint.h>
void wait_user();

uint16_t pack_register(uint8_t mode, uint8_t speed, uint8_t status)
{
uint16_t reg=0x00;
 reg |= mode;
 reg |=speed<<3;
 //reserved = ((1U<<2)-1)&(reserved>>8);
 reg|=status<<10;

 return reg;
}

int main() {
    uint8_t mode, speed, status;
    scanf("%hhu %hhu %hhu", &mode, &speed, &status);

    uint16_t reg = pack_register(mode, speed, status);
    printf("%u", reg);
    wait_user();
    return 0;
}

void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

unsigned int data(unsigned int reg,unsigned int mode,unsigned int speed,unsigned int status);
int d2b32(int reg);
void wait_user();
int main()
{
	unsigned int reg;unsigned int mode,speed,status;
printf("Enter the 16 bit register : \n");
scanf("%u",&reg);

printf("\nRegister value in Binary as :\n");
d2b32(reg);

printf("\nEnter Mode value :\n");
scanf("%u",&mode);
printf("\nEnter Speed value :\n");
scanf("%u",&speed);
printf("\nEnter Status value :\n");
scanf("%u",&status);

unsigned int result = data(reg,mode,speed,status);
printf("\nResultant 16 bit packed register value is %u\n",result);
printf("\nResultant 16 bit packed register value in binary is %u\n",result);
d2b32(result);

wait_user();
return 0;

}

int d2b32(int reg)
{
	for(int i=15;i>=0;i--)
	{
		if((reg>>i) & (1U))
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}

unsigned int data(unsigned int reg,unsigned int mode,unsigned int speed,unsigned int status)
{
	uint16_t mode_mask=0;
	uint16_t speed_mask=0;
	uint16_t status_mask=0;
	uint16_t reserved_mask=0;

	mode_mask   = mode<<0;
	speed_mask  = speed<<3;
	status_mask = status<<10;
	//reserved_mask &= ~((1U<<8)|(1U<<9));
	reg |= mode_mask|speed_mask|status_mask|reserved_mask;
	return reg;
}


void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}

