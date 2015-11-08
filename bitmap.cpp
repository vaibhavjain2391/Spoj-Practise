//the below solution is getting time limit exceeded !!

#include<iostream>
#include<string.h>
using namespace std;
void printResult(int *bitMap[182],int n,int m);
int main()
{
	int tot_cases,n,m,minDist;
	cin>>tot_cases;
	char bitMap[182][8];
	int mapOne[66300],curIndex,dx,dy;
	for(int i=0;i<tot_cases;i++)
	{
		cin>>n>>m;
		curIndex=0;
		for(int k=0;k<n;k++)
		{
			cin>>bitMap[k];
			for(int x=0;x<strlen(bitMap[k]);x++)
			{
				if((bitMap[k][x]-'0') == 1)
				{
					mapOne[curIndex++] = k; 
					mapOne[curIndex++] = x;
				}
			}
		}
		
		for(int k=0;k<n;k++)
		{
			for(int x=0;x<strlen(bitMap[k]);x++)
			{
				if((bitMap[k][x]-'0') == 1)
				{
					if(x==0)
						cout<<0;
					else
						cout<<" "<<0;
				}
				else
				{
					minDist=70000;
					for(int y=0;y<curIndex;y+=2)
					{
						if(mapOne[y] > k)
							dx= mapOne[y] - k;
						else
							dx = k - mapOne[y];
					
						if(mapOne[y+1] > x)
							dy = mapOne[y+1] - x;
						else
							dy = x - mapOne[y+1];
						if((dx + dy) < minDist)
							minDist = dx + dy;
					}
					if(x==0)
						cout<<minDist;
					else
						cout<<" "<<minDist;
				
				}
			}
			cout<<endl;
		}
		
		
	}
}


/*void printResult(int *bitMap,int n,int m)
{
	int mapOne[n*m], curColumn, curIndex, tmp;
	
	curIndex = 0; 
	
	for(int k=0;k<n;k++)
	{
		curColumn = m-1;
		tmp= bitMap[k];
		
		while(tmp>0)
		{
			if(tmp%10 == 1)
			{
				mapOne[curIndex++]=k;
				mapOne[curIndex++]=curColumn;				
			}
			tmp=tmp/10;
			curColumn--;
		
		}
	}
	
	
	char distMap[n][m];
	int minDist, dx, dy;
	for(int i=0;i<n;i++)
	{
		tmp = bitMap[i];
		for(int k=m-1;k>=0;k--)
		{
			if(tmp%10 == 1)
				distMap[i][k]='0';
			else
			{
				minDist=70000;
				for(int x=0;x<curIndex;x+=2)
				{
					if(mapOne[x] > i)
						dx= mapOne[x] - i;
					else
						dx = i - mapOne[x];
					
					if(mapOne[x+1] > k)
						dy = mapOne[x+1] - k;
					else
						dy = k - mapOne[x+1];
					if((dx + dy) < minDist)
						minDist = dx + dy;
				}
				
				distMap[i][k]= minDist + '0';
			}
			tmp = tmp/10;;
		}
	}
	
	
	
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<m;l++)
			cout<<distMap[k][l] - '0'<<" ";
		cout<<endl;
	}
}*/










