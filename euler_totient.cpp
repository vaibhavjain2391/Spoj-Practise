#include<iostream>
using namespace std;

//http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=primeNumbers 
void printEulerTotient(unsigned int n);
int main()
{
	int t;
	unsigned int n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		printEulerTotient(n);
	}
	return 0;
	
}

void printEulerTotient(unsigned int n)
{
	unsigned int result = n;
	for(int k=2;k*k<=n;k++)
	{
		if(n%k == 0)
		{
			result = result - result/k;
			do
			{
				n=n/k;
			}while(n%k==0);
		}
	}
	if(n>1) // means this number is prime
		result = result - result/n;
	cout<<result<<endl;
}	
