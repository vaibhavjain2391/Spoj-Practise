#include<iostream>
using namespace std;
int main()
{
	int tot,t;
	cin>>t;
	unsigned long long num1, num2,result,tmp;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&tot);
		scanf("%llu",&num1);
		result=0;
		for(int j=1;j<tot;j++)
		{
			scanf("%llu",&num2);
			tmp = j*(tot-j);
			result += tmp*(num2-num1);
			num1 = num2;
		}	
		printf("%llu\n",result);
	}
	return 0;
}
