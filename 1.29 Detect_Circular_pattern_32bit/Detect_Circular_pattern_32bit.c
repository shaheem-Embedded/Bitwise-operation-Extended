/*
 * Detect_Circular_pattern_32bit.c
 *
 *  Created on: Apr 7, 2026
 *      Author: SHAHEEM
 */

#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>

int d2b(int reg);
char* circular_pattern(int reg,int target);
void wait_user();

int main()
{
	int reg1,target;
	printf("\nEnter the 16 bit Source register value : \n");
	scanf("%d",&reg1);
	printf("\n16 bit Register Source register value in Binary as: \n");
	d2b(reg1);
	printf("\nEnter the 16 bit Target register value : \n");
	scanf("%d",&target);
	printf("\n16 bit Register Target register value in Binary as: \n");
	d2b(target);
	char* result = circular_pattern(reg1,target);
	printf("\n%s",result);
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
char* circular_pattern(int reg1,int target)
{
	for(int i=0;i<16;i++)
	{
		if(reg1 == target)
		{
			return "Detected Circular pattern";
		}
		reg1 = ((reg1<<i) | (reg1>>(15-i))) &0xFFFF;
	}
return "No Circular pattern detected";
}
void wait_user()
{
	while (getchar()!='\n');
	printf("\nPress Enter to Exit...!");
	getchar();
}

