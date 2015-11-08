#include<iostream>
using namespace std;
int main()
{
	int n;
	unsigned long long m;
	
	cin>>n>>m;
	int store[n];
	for(int index = 0; index<n;index++)
		cin>>store[index];
	
	int start=0,end=1, maxTillNow=store[0],curSum=store[0];
	while(end<n)
	{
		if(store[end] > m)
			curSum=0;
		else
		{
			curSum+=store[end];
			while(curSum>m)
			{
				curSum -= store[start];
				start++;
			}
			if(curSum > maxTillNow)
			{
				maxTillNow = curSum;
				if(maxTillNow == m)
					break;
			}
		}
		end++;
	}
	cout<<maxTillNow<<endl;
	return 0;
}
