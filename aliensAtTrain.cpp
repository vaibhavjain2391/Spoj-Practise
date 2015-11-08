#include<iostream>
using namespace std;
void findRes(int *store, int a, int b);
int main()
{
	int t,a,b;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		int *store = new int[a];
		for(int k=0;k<a;k++)
			scanf("%d",&store[k]);
		findRes(store,a,b);
		delete store;
	}
	return 0;
}

void findRes(int *store, int a, int b)
{
	int endptr=0,stptr=0;
	int res = 0, tmpres=0,sumtillNow=0,maxsum=0;
	
	for(endptr=0;endptr<a;endptr++)
	{
		if(store[endptr] > b)
		{
			stptr = endptr +1;
			if(tmpres == res && (maxsum > sumtillNow))
				maxsum = sumtillNow;
			else if(tmpres > res)
			{
				res = tmpres;
				maxsum = sumtillNow;
			}
			tmpres=0;
			sumtillNow=0;
		}
		else if((store[endptr]+sumtillNow)>b)
		{	
			if(tmpres == res && (maxsum > sumtillNow))
				maxsum = sumtillNow;
			else if(tmpres > res)
			{
				res = tmpres;
				maxsum = sumtillNow;
			}
			
			tmpres++;
			sumtillNow += store[endptr];
			do
			{
				sumtillNow -= store[stptr];
				tmpres--;
				stptr++;
			}while(stptr<endptr && (sumtillNow) > b);

			
		}
		else
		{
			sumtillNow += store[endptr];
			tmpres++;	
		}
		
	}
	if(tmpres == res && (maxsum > sumtillNow))
		maxsum = sumtillNow;
	else if(tmpres > res)
	{
		res = tmpres;
		maxsum = sumtillNow;
	}
	printf("%d %d\n",maxsum,res);
}







