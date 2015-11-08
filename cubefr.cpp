#include<iostream>
#include<math.h>
using namespace std;
#define N 1000100


int main()
{
	int *hash=new int[N];
	for(int i=0;i<N;i++)
		hash[i]=1;
	
	int index,tmp,mul,t,n;

	for(int i=2;i<=100;i++)
	{
		mul = i*i*i;
		hash[mul-1]=-1;
		tmp = mul+mul;
		while(tmp<=N)
		{
			hash[tmp-1]=-1;
			tmp=tmp+mul;
		}
	}
	
	index=1;
	for(int k=0;k<N;k++)
	{
		if(hash[k]==1)
		{
			hash[k]=index;
			index++;
		}
	}
	
	
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(hash[n-1] != -1)
		{
			printf("Case %d: %d\n",i+1,hash[n-1]);
		}
		else
			printf("Case %d: Not Cube Free\n",i+1);
	}
	delete hash;
	return 0;
}
















