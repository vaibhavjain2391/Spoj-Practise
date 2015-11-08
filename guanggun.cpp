#include<iostream>
using namespace std;
int main()
{
	unsigned long long n,result,properFacts;
	int tmp;
	while(cin>>n)
	{
		properFacts = n/9;
		result = properFacts*81;
		tmp = n%9;
		result += (tmp*tmp);
		printf("%llu\n",result);
		
	}
	return 0;
}
