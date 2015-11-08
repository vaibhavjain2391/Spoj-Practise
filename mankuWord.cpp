#include<iostream>
#include<math.h>
using namespace std;
void findRes(unsigned long long num);
unsigned long long pow(unsigned long long num);
int main()
{
	int t;
	unsigned long long num;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&num);
		findRes(num);
	}
	return 0;
}


void findRes(unsigned long long num)
{
	
	char *dict= "manku";
	unsigned long long factor,factpow,tmp;
	factor = ceil(log(double(num))/log(double(5)));
	
	if(factor>1)
		factpow = pow(factor-1);
		//factpow = pow(double(5), double(factor-1));
	while(factor>1)
	{
		tmp= (num-1)/factpow;
		tmp= tmp%5;
		printf("%c",dict[tmp-1]);
		factpow = factpow/5;
		factor--;
	}
	tmp= (num-1)%5;
	printf("%c\n",dict[tmp]);
}

unsigned long long pow(unsigned long long num)
{
	unsigned long long result = 1;
	for(int k=0;k<num;k++)
		result = result*5;
	return result;
}















