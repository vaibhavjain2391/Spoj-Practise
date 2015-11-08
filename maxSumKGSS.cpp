//some unfound issues in giveMaxInRange :(

#include<iostream>
#include<math.h>
using namespace std;
 long long constructTree( long long *arr,  long long *segArr, int start, int end, int segIndex);
void giveMaxInRange(int start, int end,  long long *segArr, int segStart, int segEnd,int index,  long long *max1, long long *max2 );
 long long updateValue( long long *segArr, int index,int newVal, int start, int end, int segIndex);
 long long max( long long a, long long b);
int main()
{
	int n;
	cin>>n;
	 long long *arr = new  long long[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
    
    int treeHt = (int)(ceil(log2(n)));
    int segLen = (2*(int)(pow(2,treeHt))) -1;
     long long *segArr = new  long long[segLen];
    constructTree(arr,segArr,0,n-1, 0);
    int q,x;
     long long y,result,max1,max2;
    char op;
    
    
    
	for(int k=0;k<segLen;k++)
		cout<<segArr[k]<<"\t";
	cout<<endl;
    cin>>q;
    for(int i=0;i<q;i++)
    {
    	cin>>op>>x>>y;
    	if(op=='U')
    	{
    		updateValue(segArr,x-1,y,0,n-1,0);
    		for(int k=0;k<segLen;k++)
				cout<<segArr[k]<<"\t";
			cout<<endl;
    	}
    	else
    	{
    		max1=0;
    		max2=0;
    		giveMaxInRange(x-1,y-1,segArr,0,n-1,0,&max1,&max2);
    		cout<<max1<<"\t"<<max2<<endl;
    		result=max1+max2;
			cout<<result<<endl;
    	}	
    }    
}


 long long updateValue( long long *segArr, int index,int newVal, int start, int end, int segIndex)
{
	if(index>=start && index<=end)
	{
		if(start==end)
		{
			segArr[segIndex]=newVal;
			return newVal;
		}
		else
		{
			int mid = (start+end)/2;
			 long long left = updateValue(segArr,index, newVal, start,mid, segIndex*2+1);
			 long long right = updateValue(segArr,index, newVal, mid+1,end, segIndex*2+2);
			segArr[segIndex]=max(left,right);
			return segArr[segIndex];
		}
	}	
	else
		return -1;
}

void giveMaxInRange(int start, int end,  long long *segArr, int segStart, int segEnd,int index,  long long *max1, long long *max2 )
{
	//completely outside range
	if(start>segEnd || end<segStart)
		return;

	if(segStart>=start && end>=segEnd)
	{
		if(segStart==segEnd)
		{
			if(*max1 < segArr[index])
				*max1 = segArr[index];
			else if(*max2 < segArr[index])
				*max2 = segArr[index];
		}
		else
		{
			long long first = segArr[index*2 +1];
			long long second = segArr[index*2 +2];
			
			if(first<second)
			{
				long long tmp = first;
				first=second;
				second = tmp;
			}
			if(*max1 < first)
			{
				*max1 = first;
				if(*max2 < second)
					*max2 = second;
			}
			else
			{
				if(*max1<second)
					*max1 = second;
				else if(*max2<first)
					*max2 = first;
				else if(*max2<second)
					*max2=second;
			}
		}
	}
		
	
	else
	{
		long long mid = (segStart+segEnd)/2;
		giveMaxInRange(start,end,segArr,segStart,mid,index*2+1,max1,max2);
		giveMaxInRange(start,end,segArr,mid+1,segEnd,index*2+2,max1,max2);
	}
}
 long long max( long long a, long long b)
{
	if(a>b)
		return a;
	else
		return b;
}

 long long constructTree( long long *arr,  long long *segArr, int start, int end, int segIndex)
{
	if(start>end)
		return -1;
	if(start==end)
	{
		segArr[segIndex]=arr[start];
		return arr[start];
	}
	else
	{
		int mid = (start+end)/2;
		 long long left = constructTree(arr, segArr, start,mid, segIndex*2+1);
		 long long right = constructTree(arr,segArr, mid+1, end,segIndex*2+2 );
		segArr[segIndex]= max(left, right);
		return segArr[segIndex];
	}
		
}





















