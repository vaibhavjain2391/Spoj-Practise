#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char input[2001];
	cin>>input;
	char x;
	int changes,len,openBracket,i,test_case=0;
	while(input[0]!='-')
	{
		test_case++;
		len = strlen(input);
		changes = 0;
		openBracket=0;
		for(i=0;i<len;i++)
		{
			x=input[i];
			if( x=='{')
				openBracket++;
			else
			{
				if(openBracket<=0)
				{
					changes++;
					openBracket++;
					//cout<<"inc changes\n";
				}
				else
				{
					openBracket--;
					//cout<<"deducted 1"<<endl;
				}
				
			}
		}
		changes += (openBracket/2);
		cout<<test_case<<". "<<changes<<endl;
		cin>>input;
	}
}


