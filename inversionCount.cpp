#include<iostream>
using namespace std;
void msort(int *a, int start, int end, unsigned long long *invCount);
void merge(int *a, int start, int mid, int end, unsigned long long *invCount);
int main()
{
	int t,size,n;
	unsigned long long invCount;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int *a=new int[n];
		for(int k=0;k<n;k++)
			scanf("%d",&a[k]);

		invCount=0;
		msort(a,0,n-1, &invCount);
		printf("%llu\n",invCount);
		delete a;
	}
	return 0;
}

void msort(int *a, int start, int end,unsigned long long *invCount)
{
	if(start>=end)
		return ;
	int mid = (start+end)/2;
	msort(a, start, mid,invCount);
	msort(a,mid+1, end, invCount);
	merge(a, start, mid, end, invCount);
}


void merge(int *a, int start, int mid, int end,unsigned long long *invCount)
{
	int *tmp = new int[end-start+1];
	int s1,s2,index;
	
	s1 = start;
	s2 = mid+1;
	index=0;
	
	while(s1<=mid && s2<=end)
	{
		if(a[s1] < a[s2])
			tmp[index++]=a[s1++];
		else
		{
			*invCount +=  (mid-s1 +1);
			tmp[index++]=a[s2++];
		}
	}
	
	while(s1<=mid)
		tmp[index++]= a[s1++];
	while(s2<=end)
		tmp[index++]= a[s2++];
	
	for(int k=0;k<index;k++)	
		a[k+start]=tmp[k];
}








