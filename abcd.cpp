#include<iostream>
using namespace std;
int main()
{
	int n,len,acount=0,bcount=0,ccount=0,dcount=0;
	scanf("%d",&n);
	
	len = 2*n;
	char *str = new char[len + 1];
	scanf("%s",str);
	
	for(int i=0;i<len;i++)
	{
		if(str[i]=='A')
			acount++;
		else if(str[i]=='B')
			bcount++;
		else if(str[i]=='C')
			ccount++;
		else 
			dcount++;
		
	}
	
	acount = n - acount;
	bcount = n - bcount;
	ccount = n - ccount;
	dcount = n - dcount;
	
	for(int i=0;i<len;i++)
	{
		if(str[i]=='A')
		{
			if(bcount>0)
			{
				str[i]='B';
				bcount--;
			}
			else if(ccount>0)
			{
				str[i]='C';
				ccount--;
			}
			else 
			{
				str[i]='D';
				dcount--;
			}
		}
			
		else if(str[i]=='B')
		{
			if(acount>0)
			{
				str[i]='A';
				acount--;
			}
			else if(ccount>0)
			{
				str[i]='C';
				ccount--;
			}
			else
			{
				str[i]='D';
				dcount--;
			}
		}
		else if(str[i]=='C')
		{
			if(bcount>0)
			{
				str[i]='B';
				bcount--;
			}
			else if(acount>0)
			{
				str[i]='A';
				acount--;
			}
			else
			{
				str[i]='D';
				dcount--;
			}
		}
		else 
		{
			if(bcount>0)
			{
				str[i]='B';
				bcount--;
			}
			else if(ccount>0)
			{
				str[i]='C';
				ccount--;
			}
			else 
			{
				str[i]='A';
				acount--;
			}
		}
		
	}
	printf("%s\n",str);
	
	return 0;
}
