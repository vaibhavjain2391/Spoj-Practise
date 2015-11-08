#include<iostream>
using namespace std;
int main()
{
	int tot_cases;
	unsigned long long n,tot,a;
	cin>>tot_cases;
	for(int i=0;i<tot_cases;i++)
	{
		tot=0;
		cin>>n;
		for(unsigned long long k=0;k<n;k++)
		{
			cin>>a;
			a=a%n;
			tot=tot%n;
			tot+=a;
		}
		if(tot%n == 0)
			cout<<"YES"<<endl;
		else
		 	cout<<"NO"<<endl;
	}
}
