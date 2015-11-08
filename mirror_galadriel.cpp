#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t,start,end,len;
	cin>>t;
	char str[12];
	bool magical;
	for(int i=0;i<t;i++)
	{
		magical = true;
		cin>>str;
		len = strlen(str);
		start=0, end=len-1;
		while(start<end)
		{
			if(str[start]!=str[end])
			{
				magical = false;
				break;
			}
			start++;
			end--;		
		}
		if(magical)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
