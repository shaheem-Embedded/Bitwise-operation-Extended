/*
 * Rotate_right_32bit.c
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
	printf("Enter the 32 bit register value : \n");
	scanf("%d",&reg);
	printf("\n32 bit Register value in Binary as: \n");
	d2b(reg);
	printf("\nEnter the No of Positions of the Bits to Rotate right : \n");
	scanf("%d",&pos);
	int result =rotate_right(reg,pos);
	printf("\nResulted 32 Bit register after Right rotation is %d: \n",result);
	printf("\nResulted 32 Bit register after Right rotation in Binary is: \n");
	d2b(result);
	wait_user();
}

int d2b(int reg)
{
	for(int i=31;i>=0;i--)
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
	pos = pos%32;
	reg = (reg>>pos) | (reg<<(32-pos));
    reg = reg&0xffffffff;
return reg;
}
void wait_user()
{
	while (getchar()!='\n');
	printf("\nPress Enter to Exit...!");
	getchar();
}

