/*


my ans: 0 0
=======
5 8
4
4 4
4 5
6 7
8 9
1 1 answer

my ans : 0 1
*/

#include<iostream>
#include<limits.h>
using namespace std;
void merge_sort(unsigned long long *a,int start,int end);
void merge(unsigned long long *a,int start,int mid,int end);
void printCount(unsigned long long *inTime,unsigned long long *outTime,unsigned long long start, unsigned long long end, int len);
int main()
{
	unsigned long long p,k,a,b,max,min;
	int n,len;
	struct node *head= NULL;
	unsigned long long *inTime = new unsigned long long[5001];
	unsigned long long *outTime = new unsigned long long[5001];
	for(int test=0;test<10;test++)
	{
		len=0;
		scanf("%llu%llu",&p,&k);
		scanf("%d",&n);
		for(int person=0;person<n;person++)
		{
			scanf("%llu%llu",&a,&b);
			if(!(a>k || b<p))
			{
				inTime[len]= a;
				outTime[len++]=b;
			}
		}
		if(len==0)
		{
			//cout<<"hi"<<endl;
			printf("0 0\n");
		}
		else
		{
			merge_sort(inTime, 0, len-1);
			merge_sort(outTime, 0, len-1);
			printCount(inTime,outTime,p,k,len);
		}
		
	}
	return 0;
}

void printCount(unsigned long long *inTime,unsigned long long *outTime,unsigned long long start, unsigned long long end, int len)
{
	int min=INT_MAX, max=0,curCount=0;
	
	int inIndex=0, outIndex=0;
	
	while(inIndex<len && outIndex<len && outTime[outIndex]<=end)
	{
		//cout<<"lol"<<endl;
		while(inIndex<len && (inTime[inIndex]<=outTime[outIndex]))
		{
			inIndex++;
			curCount++;
		}
		//cout<<curCount<<endl;
		if(curCount>max)
			max=curCount;
		
		if(inIndex>=len)
			break;	
		if(outTime[outIndex]<=inTime[inIndex])
		{
			outIndex++;
			curCount--;
		}
		
		if(curCount < min)
			min=curCount;
		
	}

	while(outIndex<len && outTime[outIndex]<end)
	{
		outIndex++;
		curCount--;
	}
		
	if(curCount < min)
		min=curCount;
	
	
	printf("%d %d\n",min,max);	
	
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




















