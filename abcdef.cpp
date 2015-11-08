#include<iostream>
#include <algorithm>
#include<iterator>
using namespace std;
int main()
{	
	int n;
	cin>>n;
	int store[n],tmp1,tmp2,tmp,lSize,rSize,maxSize;
	for(int i=0;i<n;i++)
		scanf("%d",&store[i]);
	
	//left : a*b + c
	//right : (e+f)*d;
	maxSize = n*n*n;
	int left[maxSize],right[maxSize];
	
	lSize=0;
	rSize=0;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(store[i]==store[j] && i<j)
			continue;
		tmp1= store[i]*store[j];
		tmp2=store[i]+store[j];
		for(int k=0;k<n;k++)
		{
			tmp  = tmp1 + store[k];
			left[lSize++] = tmp;
			if(store[k]!=0)
			{
				tmp = tmp2*store[k];
				right[rSize++]=tmp;
			}
		}
	}
	
	/*merge_sort(left,0,lSize-1);
	merge_sort(right,0,rSize-1);*/
	
	sort(left,left+lSize);
	sort(right,right+rSize);
	
	int result = 0;
	int lIndex = 0, rIndex=0,lCount, rCount;
	
	//cout<<lSize<<endl<<rSize<<endl;
	while(lIndex<lSize && rIndex<rSize)
	{
		if(left[lIndex]==right[rIndex])
		{
			lCount=1, rCount=1;
			tmp=lIndex+1;
			while(tmp<lSize && left[lIndex]==left[tmp])	
			{
				lCount++;
				tmp++;
			}
			tmp=rIndex+1;
			while(tmp<rSize && right[rIndex]==right[tmp])	
			{
				rCount++;
				tmp++;
			}
			result += (lCount*rCount);
			lIndex+= lCount;
			rIndex+= rCount;
			
		}
		else if(left[lIndex] < right[rIndex])
			lIndex++;
		else
			rIndex++;
	}
	cout<<result<<endl;
	return 0;
}

