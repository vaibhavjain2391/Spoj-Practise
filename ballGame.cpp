#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t,n;
	double res;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		res = double(n)/double(n+1);
		cout<<fixed<<setprecision(8)<<res<<endl;
	}
	return 0;
}
