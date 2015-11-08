#include<iostream>
#include<limits.h>
using namespace std;
void merge_sort(unsigned long long *a,int start,int end);
void merge(unsigned long long *a,int start,int mid,int end);
void printCount(unsigned long long *inTime,unsigned long long *outTime,int len);
int main()
{
	unsigned long long a,b,max,min;
	int n,t;
	struct node *head= NULL;
	
	scanf("%d",&t);
	for(int test=0;test<t;test++)
	{
		
		scanf("%d",&n);
		unsigned long long *inTime = new unsigned long long[n];
		unsigned long long *outTime = new unsigned long long[n];
		for(int person=0;person<n;person++)
		{
			scanf("%llu%llu",&a,&b);
			inTime[person]= a;
			outTime[person]=b;
		}
		
		merge_sort(inTime, 0, n-1);
		merge_sort(outTime, 0, n-1);
		printCount(inTime,outTime,n);	
	}
	return 0;
}

void printCount(unsigned long long *inTime,unsigned long long *outTime,int len)
{
	int max=0,curCount=0;
	
	int inIndex=0, outIndex=0;
	
	while(inIndex<len && outIndex<len)
	{
		//cout<<"lol"<<endl;
		while(inIndex<len && (inTime[inIndex]<outTime[outIndex]))
		{
			inIndex++;
			curCount++;
		}
		//cout<<curCount<<endl;
		if(curCount>max)
			max=curCount;
		
		if(inIndex>=len)
			break;	
		if(outTime[outIndex]<inTime[inIndex])
		{
			outIndex++;
			curCount--;
		}
	}


	printf("%d\n",max);	
	
}

void merge_sort(unsigned long long *a,int start,int end)
{
     if(start>=end)
      return ;
    
    int mid= (start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}

void merge(unsigned long long *a,int start,int mid,int end)
{
	int s=start,m=mid+1,e=end;
	unsigned long long *tmp=new unsigned long long[end-start+1];
	int k=0;
	while(s<=mid && m<=end)
	{
		if(a[s]>a[m])
		 {
		 	tmp[k++]=a[m++];
		 }
		 else
		 {
		 	tmp[k++]=a[s++];
		 }
	}
	while(s<=mid)
	 tmp[k++]=a[s++];
	while(m<=end)
	  tmp[k++]=a[m++];
	
	for(int i=0;i<k;i++)
	{
		a[i+start]=tmp[i];
	}
}




















