#include<iostream>
using namespace std;
unsigned long long max(unsigned long long a, unsigned long long b);
void updateMon(unsigned long long *mon,int len);
int main()
{
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		if(n>0)
		{
			unsigned long long *mon= new unsigned long long[n];
			for(int k=0;k<n;k++)
			{
				cin>>mon[k];
			}
			updateMon(mon,n);
		
			cout<<"Case "<<i+1<<": "<<mon[n-1]<<endl;
			delete mon;
		}
		else
			cout<<"Case "<<i+1<<": "<<0<<endl;
	}
	
	
}

void updateMon(unsigned long long *mon,int len)
{
	if(len<=1)
		return;
	
	mon[1]=max(mon[1],mon[0]);
	
	for(int k=2;k<len;k++)
	{
		mon[k]=max(mon[k-1], mon[k-2]+mon[k]);
	}
}

unsigned long long max(unsigned long long a, unsigned long long b)
{
	if(a>b)
		return a;
	else
		return b;
}
