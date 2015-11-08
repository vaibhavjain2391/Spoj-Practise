#include<iostream>
using namespace std;
void merge_sort(int *a,int start,int end);
void merge(int *a,int start,int mid,int end);
bool bSearch(int *store, int start, int end, int number);
int main()
{
	int n,k,count=0;
	cin>>n>>k;
	int store[n];
	for(int i=0;i<n;i++)
		cin>>store[i];
	
	merge_sort(store,0,n-1);
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(bSearch(store, 0, n-1, store[i]-k))
			count++;
		
	}
	cout<<count<<endl;
	return 0;
}


bool bSearch(int *store, int start, int end, int number)
{
	if(start>end)
		return false;
	
	int mid = (start+end)/2;
	if(store[mid]==number)
		return true;
	else if(store[mid] < number)
		return bSearch(store, mid+1, end, number);
	else
		return bSearch(store, start, mid-1, number);
}
void merge_sort(int *a,int start,int end)
{
     if(start>=end)
      return ;
    
    int mid= (start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}

void merge(int *a,int start,int mid,int end)
{
	int s=start,m=mid+1,e=end;
	int *tmp=new int[end-start+1];
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




