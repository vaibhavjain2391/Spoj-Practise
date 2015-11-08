//try to optimize it

#include<iostream>
#include<string.h>
using namespace std;
void minChanges(char *str, int len);
static short change[6100][6100];
int main()
{
	int t,len;
	cin>>t;
	char str[6101];
	for(int k=0;k<t;k++)
	{
		cin>>str;
		len = strlen(str);
		minChanges(str, len);
	}
	return 0;
}

void minChanges(char *str, int len)
{
	for(int k=0;k<len;k++)
		change[k][k]=0;
		
	for(int k=0;k<len-1;k++)
	{
		change[k][k+1]= (str[k]==str[k+1])?0:1;
	}
	
	for(int d=2;d<len;d++)
	for(int i=0;(i+d)<len;i++)
	{
		if(str[i]==str[i+d])
		{
			change[i][i+d] = change[i+1][i+d-1];
		}
		else
		{
			if(change[i+1][i+d] > change[i][i+d-1])
				change[i][i+d] = change[i][i+d-1] + 1;
			else
				change[i][i+d] = change[i+1][i+d] + 1;
		}
	}
	
	cout<<change[0][len-1]<<endl;
}
