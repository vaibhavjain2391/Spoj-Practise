#include<iostream>
using namespace std;
int lcs(int *store1, int *store2, int len1, int len2);
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int t;
	cin>>t;
	int store1[2005],store2[2005],s1Len,s2Len,x,y,curMax,resMax;
	for(int i=0;i<t;i++)
	{
		resMax=0;
		cin>>x;
		s1Len=0;
		while(x!=0)
		{
			store1[s1Len++]=x;
			cin>>x;
		}
		
		cin>>y;
		while(y!=0)
		{
			s2Len=0;
			store2[s2Len++]=y;
			cin>>x;
			while(x!=0)
			{
				store2[s2Len++]=x;
				cin>>x;
			}
			curMax = lcs(store1, store2, s1Len, s2Len);
			if(curMax > resMax)
				resMax = curMax;
			cin>>y;
		}
		cout<<resMax<<endl;
	}
	return 0;
}

int lcs(int *store1, int *store2, int len1, int len2)
{
	if(len1==0 || len2==0)
		return 0;
	int matrix[len1][len2],tmp;
	
	matrix[0][0]= (store1[0] == store2[0])?1:0;
	
	for(int i=1;i<len2;i++)
	{
		matrix[0][i]=(store1[0]==store2[i])?1:matrix[0][i-1];
	}
	
	for(int i=1;i<len1;i++)
	{
		matrix[i][0]=(store1[i]==store2[0])?1:matrix[i-1][0];
	}
	
	
	for(int i=1;i<len1;i++)
	{
		for(int j=1;j<len2;j++)
		{
			if(store1[i]==store2[j])
				matrix[i][j]=matrix[i-1][j-1] + 1;
			else
				matrix[i][j]=max(matrix[i-1][j], matrix[i][j-1]);
		}
	}
	/*for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
		cout<<matrix[i][j]<<"\t";
		
		cout<<endl;
	}	*/
	
	int res = matrix[len1-1][0];
	for(int i=1;i<len2;i++)
	{
		res = max(res, matrix[len1-1][i]);
	}
	
	return res;
}
