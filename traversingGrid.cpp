#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	unsigned long long n, m;
	for(int k=0;k<t;k++)
	{
		scanf("%llu",&n);
		scanf("%llu",&m);
		
		if(n<=m)
		{
			if(n%2==0)
				printf("L\n");
			else
				printf("R\n");
		}
		else
		{
			if(m%2==0)
				printf("U\n");
			else
				printf("D\n");
		}
	}
	return 0;
}
