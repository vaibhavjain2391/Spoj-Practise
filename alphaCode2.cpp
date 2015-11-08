#include<iostream>
#include<string.h>
using namespace std;
long long dpTotDecodings(char *number, int len);
int main()
{
	char number[100000];
	cin>>number;
	int len;
	len= strlen(number);
	long long result;
	while(number[0]!='0')
	{
		len=strlen(number);	
		result = dpTotDecodings(number, len);
		cout<<result<<endl;
		cin>>number;
	}
	return 0;
}

long long dpTotDecodings(char *number, int len)
{
	int c1,c2;
	long long dp[len+1];
	dp[0]=1;
	dp[1]=1;
	for(int k=2;k<len+1;k++)
	{
		dp[k]=0;
		c1=number[k-2]-'0';
		c2 = number[k-1]-'0';
		if(c1 == 1 || (c1==2 && c2<=6))
			dp[k]=dp[k-2];
		
		if(c2!=0)
			dp[k]+= dp[k-1];
	}
	
	return dp[len];
	
}




















