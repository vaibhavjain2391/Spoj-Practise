#include<iostream>
using namespace std;
void printSol(int *location, int size);
void merge_sort(int *a,int start,int end);
void merge(int *a,int start,int mid,int end);
int main()
{
	int location[1430];
	int n;
	cin>>n;
	while(n!=0)
	{
		for(int k=0;k<n;k++)
		{
			cin>>location[k];
		}
		merge_sort(location, 0,n-1);
		printSol(location, n);
		cin>>n;
	}
	return 0;
}


void printSol(int *location, int size)
{
	if(location[0]!=0)
	{
		//cout<<"1"<<endl;
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	
	bool possible = true;
	for(int i=1;i<size;i++)
	{
		if((location[i]-location[i-1]) > 200)
		{
			//cout<<"2"<<endl;
			possible = false;
			break;
		}
	}
	
	//Will he be able to return back ??
	if(possible && (1422-location[size-1])>100)
	{
		//cout<<3<<endl;
		possible = false;
	}
	
	
	if(possible)
		cout<<"POSSIBLE"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
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


