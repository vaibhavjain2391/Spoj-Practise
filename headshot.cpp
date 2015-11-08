#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char *str=new char[102];
	int len,empty,safe,notsafe;
	double shootprob,rotateprob;
	while(cin>>str)
	{
		len = strlen(str);
		empty=0;
		safe=0;
		notsafe=0;
		
		if(str[0]=='0')
		{
			empty=1;
			if(str[len-1] == '0')
				safe++;
			else
				notsafe++;
		}
		for(int i=1;i<len;i++)
		{
			if(str[i]=='0')
			{
				empty++;
				if(str[i-1] == '0')
					safe++;
				else
					notsafe++;
			}
		}
		//cout<<notsafe<<endl;
		//cout<<empty<<"\t"<<len<<endl;
		if(notsafe==0)
		{
			if(empty!=len)
				printf("ROTATE\n");
			else 
				printf("EQUAL\n");
		}
		else
		{
			shootprob = double(safe)/double(notsafe);
			rotateprob = double(empty)/double(len-empty);
			if(shootprob > rotateprob)
				printf("SHOOT\n");
			else if(shootprob < rotateprob)
				printf("ROTATE\n");
			else
				printf("EQUAL\n");
		}
	}
	return 0;
}









