#include<iostream>
using namespace std;
int main()
{
	int hash[10];
	for(int i=0;i<10;i++)
		hash[i]=i*i;
	
	bool firstTime[1000];
	for(int i=0;i<1000;i++)
		firstTime[i]=false;

	unsigned long long n,transit,count,tmp;
	cin>>n;
	transit =n;
	count=0;
	while(transit!=1)
	{
		tmp = 0;
		while(transit!=0)
		{
			tmp += hash[transit%10];
			transit = transit/10;
		}
		if(firstTime[tmp] || (transit == n))
			break;
		else
			firstTime[tmp]=true;
			
		transit = tmp;
		count++;
	}
	
	if(transit==1)
		cout<<count<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
