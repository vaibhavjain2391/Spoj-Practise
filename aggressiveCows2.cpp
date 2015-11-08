//using binary search method..very interesting algo !

#include<iostream>
using namespace std;
void merge_sort(long long *a,int start,int end);
void merge(long long *a,int start,int mid,int end);
long long bs_minDist( long long *stall, int totStalls, long long dstart,  long long dend,int totCows );
bool spacePossible(long long *stall,long long space,  int totStalls,int totCows);
int main()
{
	int t,totStalls, agCows;
	cin>>t;
	 long long result;
	for(int i=0;i<t;i++)
	{
		cin>>totStalls>>agCows;
		 long long *stall= new long long[totStalls];
		for(int k=0;k<totStalls;k++)
		{
			cin>>stall[k];
			
		}
		merge_sort(stall, 0, totStalls-1);
	
		result  = bs_minDist(stall,totStalls,1,(stall[totStalls-1]-stall[0]),agCows);
		cout<<result<<endl;
		delete stall;	
	}
	return 0;
}

long long bs_minDist( long long *stall, int totStalls, long long dstart,  long long dend,int totCows )
{
	if(dstart>dend)
		return 0;
	
	long long mid = (dstart+dend)/2;
	if(!(spacePossible(stall,mid, totStalls,totCows)))
	{
		if(mid == 1)
			return 0;
		else 
		{
			if(spacePossible(stall, mid-1,totStalls,totCows))
				return mid-1;
			else
				return bs_minDist(stall, totStalls, dstart, mid -1,totCows);
			
		}
	}
	else
	{
		return bs_minDist(stall, totStalls, mid+1, dend,totCows);
	}
}

bool spacePossible(long long *stall,long long space,  int totStalls,int totCows)
{
	int cowsPlaced = 1;
	int lastStallIndex = 0;
	for(int k=1;k<totStalls;k++)
	{
		if((stall[k]-stall[lastStallIndex])>=space)
		{
			cowsPlaced ++;
			lastStallIndex = k;
			if(cowsPlaced >= totCows)
				break;
		}
	}
	if(cowsPlaced >= totCows)
		return true;
	else
		return false;
}

void merge_sort( long long *a,int start,int end)
{
     if(start>=end)
      return ;
    
    int mid= (start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}

void merge( long long *a,int start,int mid,int end)
{
	int s=start,m=mid+1,e=end;
	 long long *tmp=new  long long[end-start+1];
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


		
