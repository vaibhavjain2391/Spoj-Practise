#include<iostream>
using namespace std;
void merge_sort(unsigned long long *a,int start,int end);
void merge(unsigned long long *a,int start,int mid,int end);
void printMaxDifference(unsigned long long *height,int totalStudents);
void printMinDifference(unsigned long long *height, int totalStudents,int groupSize);
int main()
{
	int t,totalStudents,groupSize;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&totalStudents);
		scanf("%d",&groupSize);
		unsigned long long *height = new unsigned long long[totalStudents];
		for(int k=0;k<totalStudents;k++)
		{
			scanf("%llu",&height[k]);
		}
		
		if(groupSize == 1)
			cout<<0<<endl;
		else if(groupSize == totalStudents)
			printMaxDifference(height, totalStudents);
		else 
		{
			merge_sort(height, 0, totalStudents-1);
			printMinDifference(height, totalStudents, groupSize);
		}
			
	}
	return 0;
}

void printMaxDifference(unsigned long long *height,int totalStudents)
{
	unsigned long long minHeight=height[0], maxHeight=height[0];
	for(int i=1;i<totalStudents;i++)
	{
		if(height[i] < minHeight)
			minHeight = height[i];
				
		else if(height[i] > maxHeight)
			maxHeight = height[i];
	}
	printf("%llu\n",maxHeight-minHeight);
}

void printMinDifference(unsigned long long *height, int totalStudents,int groupSize)
{
	
	int start = 0, end = groupSize-1;
	unsigned long long curMinDiff, minDiffSoFar=height[end]-height[start];
	start++; end++;
	while(end < totalStudents)
	{
		curMinDiff = height[end]-height[start];
		start++;end++;
		if(curMinDiff < minDiffSoFar)
			minDiffSoFar = curMinDiff; 
	}
	printf("%llu\n",minDiffSoFar);
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

