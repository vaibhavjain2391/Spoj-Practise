#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	unsigned long long result[24];
	result[0]=1;
	result[1]=3;
	for(int i=2;i<24;i++)
	{
		result[i]= 2*result[i-1] + result[i-2];
	}
	cin>>n;
	cout<<result[n]<<endl;
	return 0;
}
