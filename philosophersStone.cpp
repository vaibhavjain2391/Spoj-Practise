#include<iostream>
using namespace std;
int main()
{
	int t,rows,columns,optionDown,optionRight,optionLeft,max;
	cin>>t;
	int chamber[100][100];
	for(int k=0;k<t;k++)
	{
		cin>>rows>>columns;
		for(int x=0;x<rows;x++)
			for(int y=0;y<columns;y++)
			{
				cin>>chamber[x][y];
			}
			
		for(int x=rows-2;x>=0;x--)
		{
			for(int y=0;y<columns;y++)
			{
				optionDown = chamber[x+1][y];
				optionLeft = (y!=0)?chamber[x+1][y-1]:0;
				optionRight = (y!=(columns-1))?chamber[x+1][y+1]:0;
				
				chamber[x][y] += (optionDown>optionLeft)?((optionDown>optionRight)?optionDown:optionRight):((optionLeft>optionRight)?optionLeft:optionRight); 
			}
		}
		max = chamber[0][0];
		for(int y=1;y<columns;y++)
		{
			if(max< chamber[0][y])
				max = chamber[0][y];
		}
		cout<<max<<endl;
	}
}
