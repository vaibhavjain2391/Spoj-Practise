#include<iostream>
using namespace std;
int minOfTwo(int a ,int b)
{
	return (a<b)?a:b;
}

int minOfThree(int a ,int b, int c)
{
	int min;
	if(a<b)
	{
		if(a<c)
			return a;
		else
			return c;
	}
	else
	{
		if(b<c)
			return b;
		else
			return c;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	//handle cases for n=1 / m=1 
	int store[n][m],minCost;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		cin>>store[i][j];
	
	int startCol = 0;
	int startRow = n-2;
	while(startRow >= 0)
	{
		store[startRow][0] = store[startRow][0] + minOfTwo(store[startRow+1][0],store[startRow+1][1]);
		for(startCol=1; startCol<(m-1) ;startCol++)
		{
			store[startRow][startCol] = store[startRow][startCol] + minOfThree(store[startRow+1][startCol+1],store[startRow+1][startCol-1], store[startRow+1][startCol]);
		}
		store[startRow][m-1] = store[startRow][m-1] + minOfTwo(store[startRow+1][m-1],store[startRow+1][m-2]);
		startRow--;
		startCol=0;
	}
	
	minCost = store[0][0];
	
	for(int i=1;i<m;i++)
	{
		if(minCost > store[0][i])
			minCost = store[0][i];
	}
	cout<<minCost<<endl;
}
