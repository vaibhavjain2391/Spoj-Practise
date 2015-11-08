#include<iostream>
using namespace std;
int main()
{
	long long t,minEnergy,n,coke,energy,result;
	cin>>t;
	for(long long i=0;i<t;i++)
	{
		cin>>n;
		minEnergy=0;
		energy=0;
		for(long long k=0;k<n;k++)
		{
			cin>>coke;
			energy = energy+coke;
			if(energy<minEnergy)
				minEnergy = energy;
		}
		result = minEnergy*-1 + 1;
		cout<<"Scenario #"<<i+1<<": "<<result<<endl;
	}
	return 0;
}
