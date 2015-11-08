#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	double res;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		res=1;
		for(int k=2;k<=n;k++)
		{
			res += double(1)/double(k);
		}
		res = res*n;
		cout<<fixed<<setprecision(2)<<res<<endl;
	}
	return 0;
}
