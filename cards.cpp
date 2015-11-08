#include<iostream>
using namespace std;
int main()
{
	int t;
	unsigned long long n, result;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		result = (3*n + 1);
		result = n*result;
		result = result/2; 
		result = result%1000007;
		cout<<result<<endl;
	}
	return 0;
}
