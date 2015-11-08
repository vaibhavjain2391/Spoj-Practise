#include<iostream>
#include<string.h>
using namespace std;
void findres(char *str, int len);
int main()
{
	char *str=new char[1002];
	int len;
	while(cin>>str)
	{
		len  =strlen(str);
		findres(str, len);
	}
	return 0;
}

void findres(char *str, int len)
{
	int res1=0,res2=0;
	for(int i=0;i<len;i++)
	{
		if( str[i]>='A' && str[i]<='Z')
		{
			res2++;
		}
		else
		{
			res1++;
		}
		
		i=i+1;
		if(i<len)
		{
			if( str[i]>='A' && str[i]<='Z')
			{
				res1++;
			}
			else
			{
				res2++;
			}
		}
	}
	if(res1<res2)
		printf("%d\n",res1);
	else
		printf("%d\n",res2);
}










