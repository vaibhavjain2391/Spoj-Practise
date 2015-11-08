//Giving wrong answer..probably missing 1/2 corner case

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
	
	long long result = 1,tmp,prevResult=1,rTmp;
	int k=1;
	if(number[k]=='0')
		k++;
	for(k;k<(len-1);k++)
	{
		rTmp= result;
		if(!(number[k+1]=='0' || number[k]=='0' || number[k-1]=='0'))
		{
			tmp = (number[k-1]-'0')*10 + (number[k]-'0');
			if(tmp <=26)
			{
				result += prevResult;
			}
		}
			prevResult= rTmp;
		
	}
	//cout<<k<<endl;
	if(number[k-1]!='0' && number[k]!='0')
	{
		if(((number[k-1]-'0')*10 + (number[k]-'0')) <= 26)
		{
			result += prevResult;
		}
		
	}
	
	return result;
	
}


