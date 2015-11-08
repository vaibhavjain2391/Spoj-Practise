//accepted but not an optimal solution

#include<iostream>
using namespace std;

/*void merge_sort(int *a,int start,int end);
void merge(int *a,int start,int mid,int end);*/
int main()
{
	int t;
	int store[1000],n,m;
	unsigned long long peak,currDiff,minDiff;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int k=0;k<n;k++)
			cin>>store[k];
		
		//merge_sort(store,0,n-1);
		cin>>m;
		
		minDiff = 1000002;	
		for(int k=0;k<m;k++)
		{
			cin>>peak;
			for(int j=0;j<n;j++)
			{
				if(peak > store[j])
					currDiff=  peak - store[j];
				else
					currDiff = store[j]-peak;
			
				if(currDiff < minDiff)
					minDiff = currDiff;
			}
		} 
		cout<<minDiff<<endl;	
	}
}


/*void merge_sort(int *a,int start,int end)
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












