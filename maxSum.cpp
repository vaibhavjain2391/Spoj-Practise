//Giving TLE..Segment Trees neeed to be used

#include<iostream>
using namespace std;
void maxSum(int *store, int x, int y);
int main()
{
	int n,x,y;
	cin>>n;
	int store[n];
	for(int i=0;i<n;i++)
		cin>>store[i];
	
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		maxSum(store, x-1, y-1);
	}
	return 0;
}

void maxSum(int *store, int x, int y)
{
	int max = store[x],curSum=store[x];
	for(int k=x+1;k<=y;k++)
	{
		if(curSum < 0)
			curSum =0;
			
		if(store[k] >= 0)
			curSum += store[k];
		else
		{
			if(max < curSum)
				max = curSum;
			
			curSum += store[k];
		}
		
	}
	
	if(max < curSum)
		max = curSum;
	cout<<max<<endl;
}
