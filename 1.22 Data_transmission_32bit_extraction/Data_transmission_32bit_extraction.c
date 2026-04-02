#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int d2b32(int reg);
void wait_user();
void Data_pack(uint32_t reg,uint8_t Data_arr[4]);
uint8_t Data_arr[4];
int main()
{
uint32_t reg;
printf("Enter the 32 bit register : \n");
scanf("%u",&reg);

printf("\nRegister value in Binary as :\n");
d2b32(reg);

Data_pack(reg,Data_arr);

printf("\nArray1 Data is  %u\n",Data_arr[1]);
printf("Array2 Data is  %u\n",Data_arr[2]);
printf("Array3 Data is  %u\n",Data_arr[3]);
printf("Array4 Data is  %u\n",Data_arr[4]);

wait_user();
return 0;

}

int d2b32(int reg)
{
	for(int i=31;i>=0;i--)
	{
		if((reg>>i) & (1U))
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}

void Data_pack(uint32_t reg,uint8_t Data_arr[4])

{
	Data_arr[1] = (reg>>24 & 0XFF); //Big Endian format.
	Data_arr[2] = (reg>>16 & 0XFF);
	Data_arr[3] = (reg>>8 & 0XFF);
	Data_arr[4] = (reg>>0 & 0XFF);
}


void wait_user()
{
while(getchar()!='\n');
printf("\nPress Enter to Exit..!");
getchar();
}

