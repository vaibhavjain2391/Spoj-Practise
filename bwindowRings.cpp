#include<iostream>
using namespace std;
int main()
{
	int t,minr,minrIndex,maxr,maxrIndex,secondmaxr, secondmaxrIndex,inr,outr,num;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&num);
		scanf("%d%d",&inr,&outr);
		minr = inr;
		minrIndex= 1;
		maxr = outr;
		maxrIndex = 1;
		secondmaxr=-1;
		for(int k=1;k<num;k++)
		{
			scanf("%d%d",&inr,&outr);
			if(inr > minr)
			{
				minr = inr;
				minrIndex  = k+1;
			}
			if(outr > maxr)
			{
				secondmaxr = maxr;
				secondmaxrIndex = maxrIndex;
				maxr = outr;
				maxrIndex = k+1;
			}
			else if(outr > secondmaxr)
			{
				secondmaxr = outr;
				secondmaxrIndex  = k+1;
			}
		}
		
		if(maxrIndex == minrIndex)
		{
			maxr = secondmaxr;
		}
		
		if(maxr < minr)
			printf("%d\n",minrIndex);
		else
			printf("-1\n");
	}
	return 0;
}










