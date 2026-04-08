/*
 * Rotate_left-8Bit.c
 *
 *  Created on: Apr 7, 2026
 *      Author: SHAHEEM
 */
#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>

int d2b(int reg);
int rotate_right(int reg,int pos);
void wait_user();

int main()
{
	int reg,pos;
	printf("Enter the 8 bit register value : \n");
	scanf("%d",&reg);
	printf("\n8 bit Register value in Binary as: \n");
	d2b(reg);
	printf("\nEnter the No of Positions of the Bits to Rotate right : \n");
	scanf("%d",&pos);
	int result =rotate_right(reg,pos);
	printf("\nResulted 8 Bit register after Right rotation is %d: \n",result);
	printf("\nResulted 8 Bit register after Right rotation in Binary is: \n");
	d2b(result);
	wait_user();
}

int d2b(int reg)
{
	for(int i=7;i>=0;i--)
	{
		if((reg>>i)&1)
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}
int rotate_right(int reg,int pos)
{
reg = (reg<<pos)|(reg>>(8-pos));
reg = reg&0xff;
return reg;
}

void wait_user()
{
	while (getchar()!='\n');
	printf("\nPress Enter to Exit...!");
	getchar();
}
