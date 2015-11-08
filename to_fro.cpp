#include<iostream>
#include<string.h>
using namespace std;
void printDecodedResult(char *input, int len, int c);
int main()
{
	char *input=new char[200];
	int colms,len;
	cin>>colms;
	while(colms != 0)
	{
		cin>>input;
		len = strlen(input);
		printDecodedResult(input, len, colms);
		cin>>colms;
	}
	
}

void printDecodedResult(char *input, int len, int c)
{
	if(len==0)
		return;
	
	int refColumn = 0,nextIndex=0;
	bool turn1=true;
	cout<<input[refColumn];
	while(refColumn < c)
	{	
		if(turn1)
		{
			nextIndex += ((c*2-1) - (refColumn*2));
			turn1=false;
		}
		else
		{
			nextIndex+= (1 + (refColumn*2)) ;
			turn1=true;
		}
		
		if(nextIndex<len)
			cout<<input[nextIndex];
		
		else
		{
			refColumn++;
			turn1=true;
			nextIndex=refColumn;
			if(refColumn < c)
				cout<<input[refColumn];
		}
		
	}
	cout<<endl;
	return;
}

















