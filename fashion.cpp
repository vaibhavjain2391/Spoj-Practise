#include<iostream>
using namespace std;
void merge_sort(int *a,int start,int end);
void merge(int *a,int start,int mid,int end);
unsigned long maxHotness(int *men,int *women,int n);
int main()
{
	int tot_cases,n;
	cin>>tot_cases;
	int *men= new int[1000];
	int *women= new int[1000];
	unsigned long result=0;
	for(int i=0;i<tot_cases;i++)
	{
		cin >> n;
		for(int m=0;m<n;m++)
			cin>>men[m];
		for(int w=0;w<n;w++)
			cin>>women[w];
		
		merge_sort(men,0,n-1);
		merge_sort(women,0,n-1);
		
		/*for(int d=0;d<n;d++)
		{
			cout<<men[d];
		}
		cout<<endl;
		
		for(int d=0;d<n;d++)
		{
			cout<<women[d];
		}
		cout<<endl;*/
		
		result = maxHotness(men, women, n);
		cout<<result<<endl;
	}
}

unsigned long maxHotness(int *men,int *women,int n)
{
	unsigned long result=0;
	for(int k=0;k<n;k++)
	  result+= (men[k]*women[k]);
	return result;
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
