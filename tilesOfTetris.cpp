#include<iostream>
using namespace std;
long long findGcd(long long a, long long b);
int main()
{
	long long m,n,gcd;
	cin>>m>>n;
	long long a,b,result;
	while(m!=0)
	{
		if(m>n)
			gcd = findGcd(m,n);
		else
			gcd = findGcd(n,m);
		
		/*
		lcm = (m*n)/gcd;
		a = lcm/m;
		b = lcm/n;
		result = a*b;
		cout<<result<endl;
		*/
		
		//after doing math 
		
		a = (m*n);
		b = gcd*gcd;
		result = a/b;
		cout<<result<<endl;
		cin>>m>>n;
	}
	return 0;
}

long long findGcd(long long a, long long b)
{
        long long r;
        while(b != 0)
        {
                r = a % b;
                a = b;
                b = r;
        }
        return a;
}

