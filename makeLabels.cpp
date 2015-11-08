#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,t=0,result;
	scanf("%d",&n);
	while(n!=0)
	{
		t++;
		if(n==1 || n==2)
			result = 1;
		else if(n==3)
			result = 3;
		else
		{
			result = pow(n, n-2);
		}
		
		printf("Case %d, N = %d, # of different labelings = %d\n",t,n,result);
		scanf("%d",&n);
	}
	return 0;
}
