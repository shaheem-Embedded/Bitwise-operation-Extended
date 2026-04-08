/*
 * Extract_Bitfield_16bit.c
 *
 *  Created on: Apr 7, 2026
 *      Author: SHAHEEM
 */

#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>

int d2b(int reg);
int Extract_16bit(int reg,int len,int pos);
void wait_user();

int main()
{
	int reg,len,pos;
	printf("Enter the 16 bit register value : \n");
	scanf("%x",&reg);
	printf("\n16 bit Register value in Binary as: \n");
	d2b(reg);
	printf("\nEnter the Length of the Bits to Extract: \n");
	scanf("%d",&len);
	printf("Enter the Position of the Bits to Extract: \n");
	scanf("%d",&pos);
	int result = Extract_16bit(reg,len,pos);
	printf("\nExtracted value of the 16 Bit register is %d: \n",result);
	printf("\nExtracted value of the 16 Bit register in Binary is: \n");
	d2b(result);
	wait_user();
}

int d2b(int reg)
{
	for(int i=15;i>=0;i--)
	{
		if((reg>>i)&1)
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}
int Extract_16bit(int reg,int len,int pos)
{
int mask =0;int out;
mask = (1U<<len)-1;
out = (reg>>pos)&mask;
return out;
}

void wait_user()
{
	while (getchar()!='\n');
	printf("\nPress Enter to Exit...!");
	getchar();
}
