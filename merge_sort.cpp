#include<iostream>
using namespace std;
void msort(int *a, int start, int end);
void merge(int *a, int start, int mid, int end);
int main()
{
	int a[]={3,1,4,2,8,1};
	int size = sizeof(a)/sizeof(a[0]);
	msort(a,0,size-1);
	for(int i=0;i<size;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	return 0;
}

void msort(int *a, int start, int end)
{
	if(start>=end)
		return ;
	int mid = (start+end)/2;
	msort(a, start, mid);
	msort(a,mid+1, end);
	merge(a, start, mid, end);
}


void merge(int *a, int start, int mid, int end)
{
	int *tmp = new int[end-start+1];
	int s1,s2,index;
	
	s1 = start;
	s2 = mid+1;
	index=0;
	
	while(s1<=mid && s2<=end)
	{
		if(a[s1] < a[s2])
			tmp[index++]=a[s1++];
		else
			tmp[index++]=a[s2++];
	}
	
	while(s1<=mid)
		tmp[index++]= a[s1++];
	while(s2<=end)
		tmp[index++]= a[s2++];
	
	for(int k=0;k<index;k++)	
		a[k+start]=tmp[k];
}








