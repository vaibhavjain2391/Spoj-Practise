#include<iostream>
using namespace std;
void printNeighbours(int **mat, int n);
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int **mat= new int*[n];
		for(int i=0;i<n;i++)
			mat[i]=new int[n];
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
		
		printNeighbours(mat,n);
		
		for(int i=0;i<n;i++)
			delete mat[i];
		delete mat;
	}
}

void printNeighbours(int **mat, int n)
{
	bool found;
	int d1,d2,d3;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		found=false;
		d1 = mat[i][j];
		for(int k=0;k<n;k++)
		{
			if(k!=i && k!=j)
			{
				d2 = mat[i][k];
				d3 = mat[k][j];
				if((d2+d3) == d1)
				{
					found=true;
					break;
				}
			}
		}
		if(!found)
			printf("%d %d\n",i+1,j+1);
	}
}
















