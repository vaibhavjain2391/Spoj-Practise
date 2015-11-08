//This gives runtime error

#include<iostream>
using namespace std;
void findResult(char *store, long long mlen, long long k);
void fillStore(char *store, long long mlen);
int main()
{
	int t,n;
	scanf("%d",&t);
	unsigned long long k;
	long long mlen = 500000000000000;
 	char *store = new char[mlen+1];
 	fillStore(store, mlen);
	for(int i=0;i<t;i++)
	{
		scanf("%d%llu",&n,&k);
		cout<<k<<endl;
		findResult(store, mlen, k);
	}
	delete store;
	return 0;
}

void fillStore(char *store, long long mlen)
{
	long long curlen = 1,nextlen;
	store[0]='M';
	
	
	while(curlen< mlen)
	{
		nextlen = curlen*2;
		if(nextlen > mlen)
			nextlen = mlen;
		for(long long index=curlen;index<nextlen;index++)
		{
			if(store[index-curlen]=='M')
				store[index]='F';
			else
				store[index]='M';	
		}
		curlen=nextlen;
		
	} 
	//cout<<"oo";
}


void findResult(char *store, long long mlen,long long k)
{
	
	k=k-1;
	if(k<mlen)
	{
		if(store[k]=='M')
			printf("Male\n");
		else
			printf("Female\n");
	}
	else
	{
		if(store[k-mlen]=='M')
			printf("Female\n");
		else
			printf("Male\n");
	}
}
















