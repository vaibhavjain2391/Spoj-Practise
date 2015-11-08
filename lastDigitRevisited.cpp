#include<iostream>
#include<string.h>
using namespace std;
int lastDigit(int a, unsigned long long b);
int main()
{
	int t,len;
	unsigned long long index;
	char base[1000];
	cin>>t;
	for(int k=0;k<t;k++)
	{
		cin>>base;
		len = strlen(base);
		cin>>index;
		int result = lastDigit(base[len-1]-'0',index);
		cout<<result<<endl;
		
	}
	return 0;
}

int lastDigit(int a, unsigned long long b)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;
		
	int totDistinct=1, history[10];
	
	int firstDig = a%10;
	int curDig = (firstDig*a)%10;
	
	history[0]=firstDig;
	
	while(firstDig != curDig)
	{
		history[totDistinct]=curDig;
		totDistinct++;
		curDig = (curDig*a)%10;
		
	}	
	int index = b%totDistinct;
	if(index == 0)
		return history[totDistinct-1];
	else
		return history[index-1];
}

