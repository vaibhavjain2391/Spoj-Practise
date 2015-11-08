/*

A pattern is forming 

2 1
3 2
4 2
5 3
6 3
7 4
8 4
9 5
10 5
11 6
12 6
.
.


*/
#include<iostream>
using namespace std;
int main()
{
	int t,n,tmp;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		if(n==2) 
			cout<<1<<endl;
		else
		{
			tmp = n/2;
			if(n%2==0)
				cout<<tmp<<endl;
			else
				cout<<tmp+1<<endl;
		}
	}
}
