#include<iostream>
using namespace std;
int main()
{
	long long *store= new long long[500001];
	long long max=3100000;
	bool *hash= new bool[max];
	
	for(long long k=0;k<max;k++)
		hash[k]=false;
	
	hash[0]=true;
	store[0]=0;
	long long number,reached=0,tmp;
	cin>>number;
	while(number != -1)
	{
		if(number<=reached)
			cout<<store[number]<<endl;
		else
		{
			for(long long k=reached+1;k<=number;k++)
			{
				tmp = store[k-1]-k;
				if(tmp>0 && !hash[tmp])
				{
					/*if(tmp > max)
					{
						cout<<"bound exceeded"<<tmp<<endl;
						return 0;
					}*/
					store[k]=tmp;
					hash[tmp] = true;
				}
				else
				{
					tmp = store[k-1]+k;
					/*if(tmp > max)
					{
						cout<<"bound exceeded"<<tmp<<endl;
						return 0;
					}*/
					hash[tmp]=true;
					store[k]=tmp;
				}
			}
			cout<<store[number]<<endl;
			reached = number;
		}
		cin>>number;
	}
	return 0;
	
}
