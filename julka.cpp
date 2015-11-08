//NOT COMPLETED YET !

#include<iostream>
#include<string.h>
using namespace std;
void fillNegative(char *arr,int len);
int main()
{
	char *s= new char[102];
	char *d= new char[102];
	
	char *g1= new char[102];
	char *g2= new char[102];
	
	fillNegative(g1,102);
	fillNegative(g2,102);
	
	int slen,dlen;
	for(int i=0;i<10;i++)
	{
		cin>>s;
		cin>>d;
		
		slen= strlen(s);
		dlen = strlen(d);
		
		//g1 = (s+d)/2 , g2= (s-d)/2
		
		//putting the sum in g2(tmp array for now)
		
		add(s,d,slen,dlen,g2);
		divByTwo(g2,g1);
		
		for(int k=0;k<strlen(g1);k++)
			cout<<g1[k];
		cout<<endl;
		
		fillNegative(g1,102);
		fillNegative(g2,102);
		
		sub(s,d,slen,dlen,g1);
		divByTwo(g1,g2);
		
		for(int k=0;k<strlen(g2);k++)
			cout<<g2[k];
		cout<<endl;
		
		fillNegative(g1,102);
		fillNegative(g2,102);
		
	}
}

void fillNegative(char *arr,int len)
{
	for(int i=0;i<len;i++)
		arr[i]='-1'
}

void add(char *s, char *d, int slen, int dlen, char *result)
{
	if(slen > dlen)
	{
		
	}	
	
	
	
	
	
	
	
	
	
}











