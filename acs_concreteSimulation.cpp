#include<iostream>
#include<math.h>
using namespace std;

#define R 1234
#define C 5678

void findRes(char x, int a, int b,int *row,int *rowIndex,int *col,int *colIndex);
int main()
{
	int row[R],rowIndex[R],col[C],colIndex[C+1];

	for(int i=0;i<R;i++)
	{
		rowIndex[i]=i;
		row[i]=i;
	}
	
	for(int i=0;i<C;i++)
	{
		colIndex[i+1]=i;
		col[i]= i+1;
	}
	
	char x;
	int a, b;
	while(cin>>x)
	{
		if(x=='W')
		{
			scanf("%d",&a);
			findRes(x,a,-1,row, rowIndex, col, colIndex);
		}
		else
		{
			scanf("%d%d",&a,&b);
			findRes(x, a, b,row, rowIndex, col, colIndex);
		}
	}
	return 0;
	
}

void findRes(char x, int a, int b,int *row,int *rowIndex,int *col,int *colIndex)
{
	a=a-1;
	b=b-1;
	if(x=='R')
	{
		int tmp;
		rowIndex[row[b]]= a;
		rowIndex[row[a]] = b;
		tmp = row[a];
		row[a]=row[b];
		row[b]=tmp;
	}
	else if(x=='C')
	{
		int tmp;
		colIndex[col[b]]= a;
		colIndex[col[a]] = b;
		tmp = col[a];
		col[a]=col[b];
		col[b]=tmp;
	}
	else if(x=='Q')
	{
		int result  = C*row[a] + col[b];
		printf("%d\n",result);
	}
	else
	{
		a++;
		int resx = rowIndex[(a-1)/C];
		int resy = colIndex[((a-1)%C) + 1];
		resx++;
		resy++;
		printf("%d %d\n",resx,resy);
	}
}























