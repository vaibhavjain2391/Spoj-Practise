#include<iostream>
using namespace std;
void printInvert(int number);
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x&1 == 1)
			printf("%d\n",x);
		else
		{
			printInvert(x);
		}
	}
	return 0;
}

void printInvert(int number)
{
	int result =0,tmp;
	while(number)
	{
		tmp = number&1;
		result = (result << 1) | tmp;
		number = number >> 1;
	}
	printf("%d\n",result);
}
