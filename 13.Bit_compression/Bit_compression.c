#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int bit_compression(uint16_t val);
void wait_user();
uint8_t res=0;
int main()
{
	int val;
	printf("Enter the 16 bit register value to compressed to 8 bits: ");
			scanf("%u",&val);
			res= bit_compression(val);
			printf("The resulted compressed 8 bit Register vslue is : %u",res);

			wait_user();
			return(0);
}

int bit_compression(uint16_t val)
{
	int j=0;
	for(int i=0;i<15;i+=2)
	{
	  uint8_t out = (val>>i)&1U;
	  res |= (out <<j);
	  j++;
	}
	return res;
}
void wait_user()
{
	printf("\n Press 'Enter' to Exit..");
	while(getchar()!='\n');
	getchar();

}
