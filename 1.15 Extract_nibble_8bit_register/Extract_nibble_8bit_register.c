#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int extract_nibble(int reg,int N);

uint8_t reg;
int d2b8(uint8_t reg);
int enable_macro_config(int reg,int ENABLE,int MODE,int SPEED);
void wait_user();
int main()
{
int reg,N;

printf("Enter the 8 bit register : \n");
scanf("%d",&reg);
printf("\nRegister value in Binary as : \n");
d2b8(reg);
printf("\nEnter the Nibble position to extract \n"
		"0-->Lower Nibble value : \n"
		"1-->Higher Nibble value :\n");
scanf("%d",&N);
int result = extract_nibble(reg,N);
printf("\nExtracted Nibble value : %d\n",result);
printf("\nExtracted Nibble value value in Binary as : \n");
d2b8(result);
wait_user();
return 0;
}

int d2b8(uint8_t reg)
{
	for(int i=7;i>=0;i--)
	{
		if((reg>>i) & (1U))
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}

int extract_nibble(int reg,int N)
{
	/*int mask =0;
	int mask1 =0XF0;
	int out;

	if(N==0)
	{
		mask = (1u<<4)-1;
		out = reg & mask;
	}
	else if(N==1)
	{
		out = reg & mask1;
	}

return out;*/
	int out;
	  if(N == 0)   // Higher nibble
	    {
	        out = (reg >> 4) & 0x0F;
	    }
	    else if(N == 1)  // Lower nibble
	    {
	        out = reg & 0x0F;
	    }
	  return out;
}

void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();

}

