#include<iostream>
using namespace std;
void findRes(unsigned long long n, bool flip);
int main()
{
	int t,n;
	scanf("%d",&t);
	unsigned long long k;
	for(int i=0;i<t;i++)
	{
		scanf("%d%llu",&n,&k);
		findRes(k,false);
	}
	return 0;
}


void findRes(unsigned long long n, bool flip)
{
	if(n==1)
	{
		if(flip)
			printf("Female\n");
		else
			printf("Male\n");
	}
	else
	{
		unsigned long long tmp = n/2;
		if(n%2==0)
			return findRes(n/2,!flip);
		else
			return findRes(tmp+1,flip);
	}
}
