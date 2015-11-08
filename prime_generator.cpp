#include<iostream>
#include<math.h>
using namespace std;
void fillPrimeArray(bool *isPrime, unsigned long n, unsigned long m);
bool checkComplete(unsigned long number);
int main()
{
	int test_cases,size;
	cin>>test_cases;
	unsigned long m, n;
	bool isPrime[100001];
	for(int i=0;i<test_cases;i++)
	{
		cin>>m>>n;
		size = n-m+1;
		for(int k=0;k<size;k++)
			isPrime[k]=true;
		//cout<<"h"<<endl;
		fillPrimeArray(isPrime,n,m);
		//cout<<"m"<<endl;
		for(int k=0;k<size;k++)
		{
			if(isPrime[k])
				cout<<k+m<<endl;
		}
	}  
	return 0;
}

void fillPrimeArray(bool *isPrime, unsigned long n, unsigned long m)
{
	int size = n-m+1;
	for(int i=0;i<size;i++)
		isPrime[i]=true;
	
	
	unsigned long start=m,index=2;
	if(m==1)
		start=2;
	unsigned long potFactor = start*index;
	while(start*2 <= n)
	{
		index=2;
		if(isPrime[start-m])
		{
			potFactor = start*index;
			while(potFactor<=n)
			{
				isPrime[potFactor-m]=false;
				index++;
				potFactor = start*index;
			}
			
		}
		start=start+1;
		
	}
	
	for(int k=0;k<size;k++)
	{
		if(isPrime[k])
		{
			if(!checkComplete(k+m))
				isPrime[k]=false;
		}
	}
	
}


bool checkComplete(unsigned long number)
{
	if(number <= 1)
		return false;
	if(number <=3)
		return true;
	
	if(number%2 == 0)
		return false;
	
	unsigned long x= sqrt(number);
	if(x*x == number)
		return false;
	
	for(unsigned long k=3;k<=x;k+=2)
	{
		if(number%k == 0)
			return false;
	}
	return true;
	
}








