#include<iostream>
#include<string.h>
int findMaxCount(char *str, int len);
using namespace std;
int main()
{
	int t,len,result;
	scanf("%d",&t);
	char str[21005];
	cin.ignore(256, '\n'); 
	for(int i=0;i<t;i++)
	{
		cin.getline(str,sizeof(str));
		len = strlen(str);
		if(len==0)
			i--;
		else
		{
			result = findMaxCount(str, len);
			cout<<result<<endl;
		}
	}
	return 0;
}

int findMaxCount(char *str, int len)
{
	int index=0,count=0,resMax=1,prevCount=0,curMax=1;
	
	while(index<len && (str[index]<'a' || str[index]>'z'))
	{
		index++;
	}
	if(index==len)
		return 0;
	
	index=0;
	
	while(index<len) 
	{
		while(index<len && !(str[index]<'a' || str[index]>'z'))
		{
			index++;
			count++;
		}
		
		while(index<len && (str[index]<'a' || str[index]>'z'))
			index++;
			
		if(count==prevCount)
		{
			curMax++;
		}
		
		if(count!=prevCount || index==len)
		{
			if(curMax > resMax)
				resMax = curMax;
			curMax = 1;
			prevCount=count;
		}
		count=0;
		
	}
	return resMax;
}
