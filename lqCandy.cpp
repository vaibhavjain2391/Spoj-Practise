#include<iostream>
using namespace std;
void findRes(unsigned long long num);
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
	unsigned long long tmp=1;
	while(tmp < num)
	{
		tmp= tmp<<1;
	}
	if(tmp == num)
		printf("%llu 0\n",tmp);
	else
	{
		unsigned long long count=0,tmporg = tmp;
		while(num != 0)
		{
			tmp = tmp>>1;
			if(num>=tmp)
				num = num-tmp;
			count++; 
		}
		
		printf("%llu %llu\n",tmporg,count);
	}
}
