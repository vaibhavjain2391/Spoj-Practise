#include<iostream>
using namespace std;
int revenue[2001][2001];
int value[2001];
int main()
{
	int n,val1, val2,age;
	cin>>n;
	//int value[n];
	
	for(int i=0;i<n;i++)
		cin>>value[i];
	
	
	
	for(int i=0;i<n;i++)
		revenue[i][i] = value[i]*n;
	
	for(int d=1;d<n;d++)
	for(int x=0;(x+d)<n;x++)
	{
		//age = (x-0) + ((n-1)-(x+d));
		age = n-d;
		
		val1 = value[x]*age + revenue[x+1][x+d];
		val2 = revenue[x][x+d-1] + value[x+d]*age;
		
		if(val1 > val2)
			revenue[x][x+d] = val1;
		else
			revenue[x][x+d] = val2;
	}
	
	cout<<revenue[0][n-1]<<endl;
}
