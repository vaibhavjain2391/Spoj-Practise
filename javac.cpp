#include<iostream>
#include<string.h>
using namespace std;
bool isBig(char c)
{
	if(c>= 'A' && c<= 'Z')
		return true;
	else
	 	return false;
}

int main()
{
	char input[101];
	char output[201];
	int curIndex=0, outputIndex,len;
	bool isJava, isC, makeNextBig;
	while(cin>>input)
	{
		isJava = false;
		isC = false;
		makeNextBig = false;
		len = strlen(input);
		if(len==0 || (isBig(input[0])) || (input[0]=='_') || (input[len-1]=='_'))
			cout<<"Error!"<<endl;
		else
		{
			outputIndex = 0;
			for(curIndex=0;curIndex<len;curIndex++)
			{
				if(isBig(input[curIndex]))
				{
					isJava = true;
					if(isC)
					{
						break;	
					}
					output[outputIndex++]='_';
					output[outputIndex++]= (input[curIndex] - 'A') + 'a';
				}
				else if(input[curIndex]=='_')
				{
					isC = true;
					if(isJava || makeNextBig)
					{
						isJava =true;			
						break;	
					}
					makeNextBig = true;
				}
				else if((input[curIndex] >= 'a') && (input[curIndex] <= 'z'))
				{
					if(makeNextBig)
					{
						makeNextBig = false;
						output[outputIndex++]= (input[curIndex] - 'a') + 'A';
					}
					else
						output[outputIndex++]= input[curIndex];
				}
				else
				{
					isC = true;
					isJava = true;
				}
						
			}
			if(!(isC && isJava))
			{
				for(int k=0;k<outputIndex;k++)
					cout<<output[k];
				cout<<endl;
			}
			else
			{
				cout<<"Error!"<<endl;
			}
		}
	}
}
