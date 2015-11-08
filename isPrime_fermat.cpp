//a^p == a (mod p)

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
bool isPrime(unsigned long long n);
unsigned long long power(unsigned long long a, unsigned long long p);
int main()
{
	int t;
	unsigned long long n;
	scanf("%d",&t);
	srand(time(NULL));
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&n);
		if(isPrime(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

bool isPrime(unsigned long long n)
{
	unsigned long long a, lhs;
	for(int k=0;k<2;k++)
	{
		a = (rand()%(n-1))+1;
		lhs = power(a,n);
		if(lhs!=a)
			return false;
	}
	return true;
	
}

unsigned long long power(unsigned long long a, unsigned long long p)
{
	if(p==0)
		return 1;
	if(p==1)
		return a%p;
	unsigned long long res=1;
	res= power(a,p/2);
	if(res > p)
		res= res%p;
	res = res*res;
	
	if(res > p)
		res= res%p;
		
	if(p%2!=0)
		res= res*a;
	
	if(res > p)
		res= res%p;
	return res;
}





