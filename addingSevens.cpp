#include<iostream>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	int n, m, rIndex,index,number,tmp;

	map<int,int> hashCode;
	hashCode[63]=0;
	hashCode[10]=1;
	hashCode[93]=2;
	hashCode[79]=3;
	hashCode[106]=4;
	hashCode[103]=5;
	hashCode[119]=6;
	hashCode[11]=7;
	hashCode[127]=8;
	hashCode[107]=9;	
	
	map<int,string> revHashCode;
	revHashCode[0]='063';
	revHashCode[1]='010';
	revHashCode[2]='093';
	revHashCode[3]='079';
	revHashCode[4]='106';
	revHashCode[5]='103';
	revHashCode[6]='119';
	revHashCode[7]='011';
	revHashCode[8]='127';
	revHashCode[9]='107';
	
	cout<<revHashCode[9]<<endl;
	unsigned long long firstNo, secondNo, add;
	char *input = new char[60];
	char *result = new char[30];
	cin>>input;
	while(input[0]!='B')
	{
		index = 0;
		firstNo = 0;
		secondNo = 0;
		while(input[index]!='+')
		{
			number = 0;
			number = input[index++]-'0';
			number = (number*10) + (input[index++]-'0');
			number = (number*10) + (input[index++]-'0');
			firstNo = (firstNo*10) + hashCode[number];
		}	
		index++;
		while(input[index]!= '=')
		{
			number = 0;
			number = input[index++]-'0';
			number = (number*10) + (input[index++]-'0');
			number = (number*10) + (input[index++]-'0');
			secondNo = (secondNo*10) + hashCode[number];
		}
		cout<<firstNo<<"\t"<<secondNo<<endl;
		add = firstNo + secondNo;
		cout<<add<<endl;
		while(add>0)
		{
			tmp = add%10;
			add=add/10;
			
		}
		
		cin>>input;
		
				
	}
	hashCode.clear();
	return 0;
	
}




















