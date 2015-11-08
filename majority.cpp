#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n,count,result;
	int *store= new int[1000000];
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		scanf("%d",&store[0]);
		result = store[0];
		count=1;
		for(int k=1;k<n;k++)
		{
			scanf("%d",&store[k]);
			if(result == store[k])
				count++;
			else	
			{
				if(count==1)
					result = store[k];
				else
					count--;
			}
		}
		count=0;
		for(int k=0;k<n;k++)
		{
			if(store[k]==result)
				count++;
		}
		if(count > n/2)
			printf("YES %d\n",result);
		else
			printf("NO\n");
	}
	delete store;
}


