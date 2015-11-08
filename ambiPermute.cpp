#include<iostream>
using namespace std;
int main()
{
	int hash[100000];
	int input[100000];
	int len,number;
	cin>>len;
	bool isAmbi;
	while(len!=0)
	{
		isAmbi = true;
		for(int i=0;i<len;i++)
		{
			cin>>number;
			input[i]=number-1;
			hash[number-1]=i;
		}
				
		for(int x=0;x<len;x++)
		{
			if(hash[x] != input[x])
			{
				isAmbi = false;
				break;
			}
		}
		if(isAmbi)
			cout<<"ambiguous"<<endl;
		else	
			cout<<"not ambiguous"<<endl;
			
		cin>>len;	
	}
}
