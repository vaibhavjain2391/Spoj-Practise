#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int findmaxlen(char *store, int len)
{
 	int **mlen = new int*[len];
 	for(int i=0;i<(len);i++)
 		mlen[i] = new int[len];
 		
 	for(int i=0;i<len;i++)
 		mlen[i][i]= 1;
 	
 	char startchr, endchr;
 	
 	for(int i=0;(i+1)<len;i++)
 	{
 		startchr = store[i];
 		endchr = store[i+1];
 		if(startchr == endchr)
 			mlen[i][i+1]= 2;
 		else
 			mlen[i][i+1]=1;
 	}
 	
 	for(int diff = 2;diff <len;diff++)
 	for(int i=0;(i+diff)<len;i++)
 	{
 		startchr = store[i];
 		endchr = store[i+diff];
 		if(startchr == endchr)
 			mlen[i][i+diff]= mlen[i+1][i+diff-1] + 2;
 		else
 		{
 			mlen[i][i+diff] = max( mlen[i+1][i+diff],mlen[i][i+diff-1]);
 		}
 		
 	}
 	for(int i=0;i<len;i++)
 		cout<<mlen[0][i]<<"\t";
 	cout<<mlen[0][len-1]<<endl;
 	return mlen[0][len-1];	
	
}
int PalindromeLengthPuzzle(char* input1[])
{
	
	int len = 0;
	//while(input1[len] && ((input1[len][0]>='A' && input1[len][0]<='Z') || (input1[len][0]>='a' && input1[len][0]<='z') ))
	while(input1[len] && input1[len]!='\0')
		len++;
	
	
	cout<<len<<endl;
	int result;
	if(len==0)
		result = 0;
	else
	{		
	cout<<len<<endl;
	char *store = new char[len+1];
	for(int i=0;i<len;i++)
	{
		store[i]=input1[i][0];
		if(!(store[i]<='z' && store[i]>='a') ||(store[i]>='A' && store[i]<='Z'))
		{
			len = i;
			break;
		}
	}
	for(int i=0;i<len;i++)
	{
		cout<<store[i]<<"\t";
	}
	result = findmaxlen(store, len);}
	return result;
}
int main()
{
	char* input1[]={"b","b","b","b"};
	int result = PalindromeLengthPuzzle(input1);
	cout<<result<<endl;
}
