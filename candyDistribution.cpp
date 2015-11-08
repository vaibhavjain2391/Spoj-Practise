#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long n;
	cin>>n;
	unsigned long long *students = new unsigned long long[100001];
	unsigned long long *price = new unsigned long long[100001];
	unsigned long long result,i;
	while(n!=0)
	{
		result=0;
		for(i=0;i<n;i++)
		{
			cin>>students[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>price[i];
		}
		sort(students,students+n);
		sort(price, price+n);
		
		for(i=0;i<n;i++)
		{
			result += (students[i]*price[n-i-1]);
		}
		cout<<result<<endl;
		cin>>n;
	}
	return 0;
}
