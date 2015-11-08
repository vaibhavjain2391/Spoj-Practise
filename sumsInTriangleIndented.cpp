#include<iostream>
using namespace std;
int main()
{
	int t,store[5050],n,tot,row,columns,k,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		tot = (n*(n+1))/2;
		for(k=0;k<tot;k++)
			scanf("%d",&store[k]);
		tot = tot-n-1;
		row = n-1;
		columns = row;
		for(k=tot;k>=0;k--)
		{
			store[k] = store[k] + ((store[k+row]>store[k+row+1])?store[k+row]:store[k+row+1]);
			if(columns==1)
			{
				row--;
				columns = row;
			}
			else
				columns--;
		}
		printf("%d\n",store[0]);
	}
	return 0;
}

