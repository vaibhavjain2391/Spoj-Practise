//wrong way 

#include<iostream>
using namespace std;
void dpMinCash(int weight,int coinsType,int* value,int* wt);
int main()
{
	int t;
	cin>>t;
	int empty,filled,weight,coinsType;
	int *value = new int[50000];
	int *wt = new int[10000];
	for(int i=0;i<t;i++)
	{
		cin>>empty>>filled;
		weight = filled - empty;
		
		
		cin>>coinsType;
		for(int k=0;k<coinsType;k++)
		{
			cin>>value[k];
			cin>>wt[k];
		}
		if(weight<=0)
			cout<<"This is impossible."<<endl;
		else
			dpMinCash(weight, coinsType, value, wt);
	}
}


void dpMinCash(int weight,int coinsType,int* value,int* wt)
{
	
	int **minValue = new int*[coinsType+1];
	for(int k=0;k<coinsType+1;k++)
		minValue[k]=new int[weight+1];
		
	
	for(int i=1;i<weight;i++)
		minValue[0][i]=-1;
	
	for(int i=0;i<coinsType;i++)
		minValue[i][0]=0;
	
	int tmp,tmp2,tmp3;
	for(int i=1;i<=coinsType;i++)
	for(int j=1;j<=weight;j++)
	{
		minValue[i][j]=minValue[i-1][j];
		if(wt[i-1]!=0)
		{
			tmp = j/wt[i-1];
			while(tmp > 0)
			{
				tmp2 = minValue[i-1][j-tmp*wt[i-1]];
				if(tmp2 != -1)
				{
					tmp3 = tmp*value[i-1] + tmp2;
					if(minValue[i][j]==-1)
						minValue[i][j] = tmp3;
					
					else if(tmp3 < minValue[i][j])
						minValue[i][j] = tmp3;
				}
				tmp--;
			}
		}	
	}
	
	if(minValue[coinsType][weight] <= 0)
		cout<<"This is impossible."<<endl;
	
	else
		cout<<"The minimum amount of money in the piggy-bank is "<<minValue[coinsType][weight]<<"."<<endl;
	
}









