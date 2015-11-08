//Not done

#include<iostream>
#include<string.h>
using namespace std;
void changeToNextPalin(char *str, int len);
int main()
{
	char str[1000002]; //to handle the case of 999..next palin is 1001
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",str);
		changeToNextPalin(str, strlen(str));
		printf("%s\n",str);
	}
}

void changeToNextPalin(char *str, int len)
{
	int mid = len/2;
	int left,right;
	if(len%2==0)
	{
		left = mid-1;right=mid;
		while(left>=0 && str[left]==str[right])
		{
			left--;right++;	
		}
		
		//already a palindrome..increase mid by 1 
		if(left<0)
			incByOne(str,len,mid-1,mid);
			
			
		if(str[mid-1] > str[mid])
		{
			str[mid]=str[mid-1];
			copyLeftToRight(str, len, mid-2, mid+1);
		}
		else if(str[mid-1] != 9)
		{
			
		}
	}
	
	else
	{
		//not correct
		if(str[mid]!=9)
		{
			str[mid]=((str[mid]-'0')+1) + '0';
			copyLeftToRight(str, len, mid-1, mid+1);
		}
		else
		{
			//handle overflow situation
		}
	}
}
