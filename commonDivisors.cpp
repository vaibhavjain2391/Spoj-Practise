//The solution boils down to finding the number of divisor of the GCD of the two numbers.

#include<iostream>
#include<math.h>
using namespace std;
void totDivisors(int a, int b);
int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	int a,b,t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		totDivisors(a,b);
	}
	return 0;
}

void totDivisors(int a, int b)
{
	int gcdRes;
	if(a>b)
		gcdRes = gcd(a,b);
	else if(a<b)
		gcdRes = gcd(b,a);
	else
		gcdRes=a;
	
	//cout<<gcdRes<<endl;
	
	if(gcdRes==1)
		printf("1\n");
	else{

	int sqGcdRes = sqrt(gcdRes); 
	int result=2,maxRight; //1 for gcdRes , 1 for '1'
	if((sqGcdRes*sqGcdRes) == gcdRes) 
	{
		maxRight  = sqGcdRes-1;
		result++;
	}
	else
		maxRight  = sqGcdRes;
		
	for(int k=2;k<=maxRight;k++)
	{
		if(gcdRes%k==0)
			result+=2;
	}
	printf("%d\n",result);
	
}
}

























