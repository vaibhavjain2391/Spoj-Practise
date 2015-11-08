#include<iostream>
using namespace std;
int main()
{
	int n,t1,t2,t3;
	cin>>n;
	while(n!=0)
	{
		if(n==1)
			cout<<5<<endl;
		else if(n==2)
			cout<<12<<endl;
		else
		{
			t1 = 5*n;
			t2 = 2*(n-1);
			t3 = 3*((n-2)*(n-1)/2);
			cout<<t1+t2+t3<<endl;
		}
		cin>>n;
	}
	return 0;
}
