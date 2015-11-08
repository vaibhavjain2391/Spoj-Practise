#include<iostream>
using namespace std;
int findGcd(int a , int b);
int main()
{
	int n;
	scanf("%d",&n);
	if(n==0 || n==1)
		cout<<0<<endl;
		
	else
	{
		int firstPosition, position,curGcd,result,tmp,prevPosition;
		scanf("%d",&firstPosition);
		scanf("%d",&position);
		curGcd = position-firstPosition;
		for(int i=2;i<n;i++)
		{
			prevPosition = position;
			scanf("%d",&position);
			tmp = position - prevPosition;
			if(tmp>curGcd)
				curGcd= findGcd(tmp, curGcd);
			else
				curGcd= findGcd(curGcd, tmp);
		}
		
		result = ((position - firstPosition)/curGcd) - (n-1);
		printf("%d\n",result);
	}
	
	return 0;
}


int findGcd(int a , int b)
{
	if(b==0)
        return a;
    else
        return findGcd(b, a % b);
	
}





