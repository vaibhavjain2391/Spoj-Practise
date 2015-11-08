#include<iostream>
#include<string.h>
using namespace std;
void printResult(char *str, int len);
long long gcd(long long a, long long b)
{
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int main()
{
	char str[101];
	scanf("%s",str);
	int len;
	while(str[0]!='*')
	{
		len = strlen(str);
		printResult(str,len);
		scanf("%s",str);
	}
}

void printResult(char *str, int len)
{
	long long lcmtillNow=1,tmp,gcdRes;
	for(int k=len-1;k>=0;k--)
	{
		if(str[k]=='Y')
		{
			gcdRes = gcd(k+1, lcmtillNow);
			tmp = (lcmtillNow*(k+1))/gcdRes;
			lcmtillNow = tmp;
		}
	}
	
	for(int k=len-1;k>=0;k--)
	{
		if(str[k]=='N')
		{
			if((lcmtillNow%(k+1))==0)
			{
				lcmtillNow = -1;
				break;
			}
		}
	}
	printf("%lld\n",lcmtillNow);
}
