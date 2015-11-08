///facing some errors 

#include<iostream>
using namespace std;

void merge_sort(long long *a,long long start,long long end);
void merge(long long *a,long long start,long long mid,long long end);
int main()
{
	long long t;
	long long store1[1000],store2[1000],n,m;
	 long long currDiff,minDiff,s2;
	cin>>t;
	for(long long i=0;i<t;i++)
	{
		cin>>n;
		for(long long k=0;k<n;k++)
			cin>>store1[k];
		
		merge_sort(store1,0,n-1);
		cin>>m;
		
		
		for(long long k=0;k<m;k++)
			cin>>store2[k];
		
		merge_sort(store2,0,m-1);
		minDiff = 1000002;	
		
		s2 = 0;
		for(long long s1=0;s1<n;s1++)
		{
			
			while(s2<m && (store1[s1] >= store2[s2]))
			{
				currDiff = store1[s1]-store2[s2];
				s2++;
			}
			if(currDiff < minDiff)
				minDiff=currDiff;
			
			if(s2>=m)
				break;
					
			currDiff = store2[s2]-store1[s1];
			if(currDiff < minDiff)
				minDiff=currDiff;
		}
		cout<<minDiff<<endl;	
	}
}


void merge_sort(long long *a,long long start,long long end)
{
     if(start>=end)
      return ;
    
    long long mid= (start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}

void merge(long long *a,long long start,long long mid,long long end)
{
	long long s=start,m=mid+1,e=end;
	long long *tmp=new long long[end-start+1];
	long long k=0;
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
	
	for(long long i=0;i<k;i++)
	{
		a[i+start]=tmp[i];
	}
}












