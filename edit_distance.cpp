#include<iostream>
#include<string.h>
using namespace std;
int findEditDistance(char *a, char *b, int alen, int blen);
int min(int a, int b, int c)
{
	if(a<b)
	{
		if(a<c)
			return a;
		else
			return c;
	}
	
	else
	{
		if(b<c)
			return b;
		else
			return c;
	}
}
int main()
{
	int test_cases,alen,blen,result;
	char a[2010];
	char b[2010];
	
	cin>>test_cases;
	for(int i=0;i<test_cases;i++)
	{
		cin>>a;
		cin>>b;
		
		alen = strlen(a);
		blen = strlen(b);
		
		result = findEditDistance(a,b, alen, blen);
		cout<<result<<endl;
		
	}
	return 0;
}

int findEditDistance(char *a, char *b, int alen, int blen)
{
	if(alen==0 && blen==0)
		return 0;
		
	if(alen==0)
		return blen;
		
	if(blen==0)
		return alen;
		
	
	//considering a as row and b as colum
	//can be optimized..choose row as min(alen,blen)  
	
	int infoCurRow[alen+1];
	int infoLastRow[alen+1];
	
	for(int i=0;i<alen+1;i++)
	{
		infoLastRow[i] = i;
		infoCurRow[i] = i;
	}
	
	int curColumn = 1;
	while(curColumn <= blen)
	{
		infoCurRow[0] = curColumn;
			  
		for(int i=1;i<alen+1;i++)
		{
			if(b[curColumn-1] == a[i-1])
				infoCurRow[i]= min(infoLastRow[i]+1, infoCurRow[i-1]+1, infoLastRow[i-1]);
			else
				infoCurRow[i]= min(infoLastRow[i]+1, infoCurRow[i-1]+1, (infoLastRow[i-1]+1));
		}
		
		/*for(int k=0;k<alen;k++)
		cout<<infoCurRow[k]<<"   ";
	cout<<endl;
	
	for(int k=0;k<alen;k++)
		cout<<infoLastRow[k]<<"   ";
	cout<<endl;*/
	
		for(int k=0;k<alen+1;k++)
			infoLastRow[k] = infoCurRow[k];
		curColumn++;
	}
		
	
	return infoCurRow[alen];
}














