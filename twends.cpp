#include<iostream>
#include<stdlib.h>
using namespace std;
int maxLoss(int *store, int start, int end);
int dp_maxLoss(int *store, int n);
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int n,cost,index=0;
	int store[1000];
	scanf("%d",&n);
	while(n!=0)
	{
		index++;
		for(int i=0;i<n;i++)
			scanf("%d",&store[i]);
		//cost = maxLoss(store,0, n-1);
		cost = dp_maxLoss(store,n);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",index,cost);
		scanf("%d",&n);
	}
	return 0;
}



int dp_maxLoss(int *store, int n)
{
	int cost[n][n];
	int cost1, cost2,start, end;
	
	for(int i=0;i<n-1;i++)
		cost[i][i+1] = abs(store[i]-store[i+1]);
	
	for(int d=3;d<n;d+=2)
	for(int i=0;(i+d)<n;i++)
	{
		start = i;
		end = i+d;
		//first person chooses store[start]
		if(store[start+1] >= store[end])
			cost1 = store[start] - store[start+1] + cost[start+2][end];
		else
			cost1 = store[start] - store[end] + cost[start+1][end-1];
	
		//first person chooses store[end]
		if(store[start] >= store[end-1])
			cost2 = store[end] - store[start] + cost[start+1][end-1];
		else
			cost2 = store[end] - store[end-1] + cost[start][end-2];
	
		if(cost1<0 && cost2<0)
			cost[i][i+d] = min(cost1, cost2);
		else
			cost[i][i+d] = max(cost1, cost2);
	}
	return cost[0][n-1];
}



int maxLoss(int *store, int start, int end)
{
	if(start>=end)
		return 0;
	
	int cost1, cost2;
	
	//first person chooses store[start]
	if(store[start+1] >= store[end])
		cost1 = store[start] - store[start+1] + maxLoss(store, start+2, end);
	else
		cost1 = store[start] - store[end] + maxLoss(store, start+1, end-1);
	
	//first person chooses store[end]
	if(store[start] >= store[end-1])
		cost2 = store[end] - store[start] + maxLoss(store, start+1, end-1);
	else
		cost2 = store[end] - store[end-1] + maxLoss(store, start, end-2);
	
	if(cost1<0 && cost2<0)
		return min(cost1, cost2);
	else
		return max(cost1, cost2);
}


















