#include<iostream>
using namespace std;
int main()
{
	int t,start;
	cin>>t;
	unsigned long long n;
	for(int k=0;k<t;k++)
	{
		cin>>n>>start;
		if(start == 0)
		{
			cout<<"Airborne wins."<<endl;
		}
		else
			cout<<"Pagfloyd wins."<<endl;
	}
	return 0;
}
