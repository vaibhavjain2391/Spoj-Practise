#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int history[10000],result=0,mean;
	unsigned long long total=0;
	while(n!=-1)
	{
		for(int i=0;i<n;i++)
		{
			cin>>history[i];
			total += history[i];
		}
		if(total%n != 0)
			cout<<"-1"<<endl;
		else
		{
			mean = total/n;
			for(int k=0;k<n;k++)
			{
				if(history[k] > mean)
					result += (history[k]-mean);
			}
			cout<<result<<endl;
		}	
		cin>>n;
		total=0;
		result=0;
	}
}
