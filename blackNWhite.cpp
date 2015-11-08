#include<iostream>
#include<string.h>
using namespace std;
void printResult(char *a, char *b, int len);
int main()
{
	char *a = new char[502];
	char *b = new char[502];
	cin>>a>>b;
	int len;
	while(a[0]!='*' && b[0]!='*')
	{
		len = strlen(a);
		printResult(a,b,len);
		cin>>a>>b;
	}
	return 0;
}

void printResult(char *a, char *b, int len)
{
	int curIndex=0, result = 0;
	while(curIndex<len)
	{
		while(curIndex<len && a[curIndex]==b[curIndex])
			curIndex++;
		if(curIndex<len && a[curIndex]!=b[curIndex])
		{
			while(curIndex<len && a[curIndex]!=b[curIndex])
				curIndex++;
			result++;
		}
	}
	cout<<result<<endl;
}
