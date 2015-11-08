//Program needs lazy propagation/BITS implementation 

#include<iostream>
#include<math.h>
using namespace std;
//void constructTree(long long  *segArr, long long  start, long long  end, long long  segIndex);
long long giveTotInRange(long long start,long long end, long long  *segArr, long long segStart,long long segEnd,long long index);
long long updateValue(long long  *segArr,long long qStIndex,long long qEnIndex,long long  newVal, long long start, long long end, long long segIndex);
int main()
{
	long long v,result;
	long long treeHt,segLen,t,n,c,type,p,q;
	scanf("%lld",&t);
	for(long long i=0;i<t;i++)
	{
		scanf("%lld",&n);
		long long treeHt = (long long)(ceil(log2(n)));
    	long long segLen = (2*(long long)(pow(2,treeHt))) -1;
		
		long long  *segArr = new long long[segLen];
		for(long long k=0;k<segLen;k++)
			segArr[k]=0;
		//constructTree(segArr,0,n-1, 0);
		
		scanf("%lld",&c);
		for(long long k=0;k<c;k++)
		{
			scanf("%lld",&type);
			if(type==0)
			{
				scanf("%lld%lld%lld",&p,&q,&v);
				updateValue(segArr,p-1,q-1,v,0,n-1,0);
				
				/*for(long long m=0;m<segLen;m++)
					cout<<segArr[m]<<"\t";
					cout<<endl;
				*/
			}
			else
			{
				scanf("%lld%lld",&p,&q);
				result= giveTotInRange(p-1,q-1,segArr,0,n-1,0);
				printf("%lld\n",result);
			}
		}
		delete segArr;
	}
	
	return 0;
}


long long updateValue(long long  *segArr, long long qStIndex,long long qEnIndex,long long  newVal, long long start, long long end, long long segIndex)
{
	//return the number of entries updated below you
	if(!(qStIndex>end || qEnIndex<start))
	{
		if(start==end)
		{
			segArr[segIndex]+=newVal;
			return 1;
		}
		else
		{
			long long mid = (start+end)/2;
			long long left = updateValue(segArr,qStIndex, qEnIndex, newVal, start,mid, segIndex*2+1);
			long long right = updateValue(segArr,qStIndex,qEnIndex,  newVal, mid+1,end, segIndex*2+2);
			segArr[segIndex]+=((left+right)*newVal);
			return (left+right);
		}
	}	
	else
		return 0;
}

long long giveTotInRange(long long start,long long end, long long  *segArr, long long segStart,long long segEnd,long long index)
{
	//completely outside range
	if(start>segEnd || end<segStart)
		return 0;
	//compl
	if(start<=segStart && end>=segEnd)
		return segArr[index];
	
	else
	{
		long long  left = giveTotInRange(start,end,segArr,segStart,(segEnd+segStart)/2,index*2+1);
		long long  right = giveTotInRange(start,end,segArr,(segEnd+segStart)/2+1,segEnd,index*2+2);
		return (left + right);
	}
}









