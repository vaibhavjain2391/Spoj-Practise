#include<iostream>
using namespace std;
void printResult(unsigned long long a, unsigned long long b, bool *prime);
unsigned long long min(unsigned long long a, unsigned long long b);
int main()
{
	unsigned long long maxInput = 1000000001,a,b;
	bool *prime=new bool[maxInput];
	for(unsigned long long i=5;i<maxInput;i+=2)
		prime[i]=true;
	
	prime[0]=false;
	prime[1]=false;
	prime[2]=true;
	prime[3]=true;
	unsigned long long start=3;
	while(start<maxInput)
	{
		for(unsigned long long i=start+2;i<maxInput;i+=2)
		{
			if(prime[i] && (i%start==0))
				prime[i]=false;
		}
		start++;
		while(start<maxInput && prime[start]==false)
			start+=2;
	}

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		printResult(a,b,prime);
	}
	
	return 0;
}

unsigned long long min(unsigned long long a, unsigned long long b)
{
	if(a<b)
		return a;
	else
		return b;
	
}

void printResult(unsigned long long a, unsigned long long b, bool *prime)
{

	unsigned long long x=min(a,b),start=2;
	while(start<a && start<b)
	{
		while(a%start==0 && b%start==0)
		{
			a=a/start;
			b=b/start;
		}
	}
	start=3;
	x=min(a,b);
	while(start<x)
	{
		while(a%start==0 && b%start==0)
		{
			a=a/start;
			b=b/start;
		}
		x=min(a,b);
		start+=2;
		while(start<x && prime[start]==false)
			start+=2;
	}
	cout<<b<<" "<<a<<endl;
}

























