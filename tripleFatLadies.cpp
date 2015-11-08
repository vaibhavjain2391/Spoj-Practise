#include<iostream>
using namespace std;
int main()
{
	int test_cases;
	int store[4]= {942,192,442,692};
	unsigned long long k,result;
	cin>>test_cases;
	for(int i=0;i<test_cases;i++)
	{
		cin>>k;
		result = (k-1)/4;
		result = result*1000 + store[k%4];
		cout<<result<<endl;
	}
	return 0;
}
