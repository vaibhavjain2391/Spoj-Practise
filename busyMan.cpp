#include<iostream>
using namespace std;
void maxAct(struct node *head, int n);
void merge_sort(struct node *a,int start,int end);
void merge(struct node *a,int start,int mid,int end);
struct node{
	int start;
	int end;
};

int main()
{
	int t,n,start,end;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		struct node *store = new node[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d%d",&(store[j].start),&(store[j].end));
		}
		merge_sort(store, 0, n-1);
		maxAct(store, n);
		delete store;
	}
}

void merge_sort(struct node *a,int start,int end)
{
     if(start>=end)
      return ;
    
    int mid= (start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}

void merge(struct node *a,int start,int mid,int end)
{
	int s=start,m=mid+1,e=end;
	struct node *tmp=new node[end-start+1];
	int k=0;
	while(s<=mid && m<=end)
	{
		if(a[s].end>a[m].end)
		 {
		 	tmp[k].start = a[m].start;
		 	tmp[k++].end = a[m++].end;
		 }
		 else
		 {
		 	tmp[k].start = a[s].start;
		 	tmp[k++].end = a[s++].end;
		 }
	}
	while(s<=mid)
	{
	 	tmp[k].start = a[s].start;
		tmp[k++].end = a[s++].end;
	}
	while(m<=end)
	{
	  	tmp[k].start = a[m].start;
		tmp[k++].end = a[m++].end;
	}
	
	for(int i=0;i<k;i++)
	{
		a[i+start].start=tmp[i].start;
		a[i+start].end=tmp[i].end;
	}
}


void maxAct(struct node *store, int n)
{
	if(n==0)
	{
		printf("0\n");
		return;
	}
	int lastEnd = store[0].end;
	int result=1;
	for(int k=1;k<n;k++)
	{
		if(store[k].start >= lastEnd)
		{
			result++;
			lastEnd = store[k].end;
		}
	}
	printf("%d\n",result);
}

