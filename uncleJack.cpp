#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,d;
	unsigned long long res;
	cin>>n>>d;
	while(n!=0 && d!=0)
	{
		res= pow(n,d);
		cout<<res<<endl;
		cin>>n>>d;
	}
	return 0;
}
