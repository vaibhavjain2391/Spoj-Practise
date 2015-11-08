#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[1001];
	char b[1001];
	int ahash[26],alen,blen,bhash[26],count;
	char x;
	while(cin>>a)
	{
		cin>>b;
		alen = strlen(a);
		blen = strlen(b);
		for(int i=0;i<26;i++)
		{
			ahash[i]=0;
			bhash[i]=0;
		}
		for(int i=0;i<alen;i++)
			ahash[a[i]-'a']++;
		
		for(int i=0;i<blen;i++)
			bhash[b[i]-'a']++;
			
		for(int i=0;i<26;i++)
		{
			count = (ahash[i]<bhash[i])?ahash[i]:bhash[i];
			x = 'a' + i;
			while(count!=0)
			{
				cout<<x;
				count--;
			}
		}
		cout<<endl;
	}
}
