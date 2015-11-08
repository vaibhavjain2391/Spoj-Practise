#include<iostream>
using namespace std;
void merge_sort(int *a,int start,int end);
void merge(int *a,int start,int mid,int end);
int main()
{
	int scenarios,friends,needed,count,index;
	int friendCollection[1000];
	unsigned long long maxWithFriends, sumTillNow;
	cin>>scenarios;
	for(int k=0;k<scenarios;k++)
	{
		cin>>needed;
		cin>>friends;
		maxWithFriends = 0;
		
		for(int f=0;f<friends;f++)
		{
			cin>>friendCollection[f];
			maxWithFriends += friendCollection[f];
		}
		cout<<"Scenario #"<<k+1<<":"<<endl;
		if(maxWithFriends < needed)
			cout<<"impossible"<<endl;
		
		else if(maxWithFriends == needed)
			cout<<friends<<endl;
			
		else
		{
			merge_sort(friendCollection,0,friends-1);
			sumTillNow = 0,count=0,index = friends-1;
			while(sumTillNow < needed)
			{
				sumTillNow += friendCollection[index--];
				count++;
			}
			cout<<count<<endl;
		}
		
		cout<<endl;	
	}
	return 0;
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



