#include<iostream>
using namespace std;
int main()
{
	int n;
	unsigned long long xorResult, x;
	scanf("%d",&n);
	scanf("%llu",&xorResult);
	for(int i=1;i<n;i++)
	{
		scanf("%llu",&x);
		xorResult = xorResult^x;
	}
	printf("%llu\n",xorResult);
	return 0;
}
