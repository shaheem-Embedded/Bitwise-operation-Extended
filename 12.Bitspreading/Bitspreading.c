#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

uint16_t res=0;
int bit_spreading(uint8_t val);
void wait_user_input();

int main()
{
	uint8_t val=0;
	printf("\nEnter the 8 bit register to Spread with interleave 0 bits: ");
	scanf("%u",&val);
	res = bit_spreading(val);
	printf("\n Resulted 16 bit Register is: %u\n",res);
	wait_user_input();
	return(0);
}
int bit_spreading(uint8_t val)
{
	uint16_t out=0;int j=0;
	for(int i=0;i<8;i++)
	{
	 out = (val>>i)&1U;
	 res|= out<<j;
	 j+=2;
	}
	return res;
}
void wait_user_input()
{
	while(getchar()!='\n');
	printf("\nPress 'Enter'to Exit");
	getchar();

}
