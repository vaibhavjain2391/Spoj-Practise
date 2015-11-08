#include<iostream>
using namespace std;
int main()
{
	int t;
	unsigned long long b,c,d,tmp,result;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%llu%llu%llu",&b,&c,&d);
		result = 2*c;
		tmp = b+d;
		
		if(tmp>result)
			result = tmp-result;
		else
			result = result - tmp;
		printf("%llu\n",result); 
		
	}
	return 0;
}
