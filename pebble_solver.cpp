#include<iostream>
#include<string.h>
using namespace std;
int findRes(char *str, int len);
int main()
{
	int count,len,result,num;
	char str[1000000];
	count=1;
	//while(~scanf("%s",str))
	while(cin>>str)
	{
		num=1;
		result=0;
		len = strlen(str);
		//result = findRes(str, len);
		for(int i=0;i<len;i++)
		{
			if(str[i]=='0' + num)
				{
					result++;
					if(num==0)
						num=1;
					else
						num=0;
				}
		}
			
			
		printf("Game #%d: %d\n",count,result);
		count++;
	}
	return 0;
}

int findRes(char *str, int len)
{
	int count = 0,num=1;
	
	for(int i=0;i<len;i++)
	{
		if(str[i]=='0' + num)
			{
				count++;
				if(num==0)
					num=1;
				else
					num=0;
			}
	}
	return count;
}

//Though this method is also O(n), it gives TLE. 
/*void findRes(char *str, int len)
{
	bool flip =  false;
	int count = 0;
	
	for(int i=0;i<len;i++)
	{
		if(!flip)
		{
			if(str[i]=='1')
			{
				flip=true;
				count++;
			}
			
		}
		else
		{
			if(str[i]=='0')
			{
				flip=false;
				count++;
			}
			
		}
	}
	printf("%d\n",count);
}*/
