#include<iostream>
#include<string.h>
using namespace std;
bool possible(int *inHash,int *outHash, int *sameEnds);
int main()
{
	int t,len,n;
	scanf("%d",&t);
	char *str=new char[1001];
	int inHash[26];
	int outHash[26];
	int sameEnds[26];
	int c1,c2;
	bool allSame;
	for(int i=0;i<t;i++)
	{
		for(int k=0;k<26;k++)
		{
			inHash[k]=0;
			outHash[k]=0;
			sameEnds[k]=0;
		}
		scanf("%d",&n);
		for(int k=0;k<n;k++)
		{
			scanf("%s",str);
			len=strlen(str);
			c1 = str[0]-'a';
			c2 = str[len-1]-'a';
			if(c1==c2)
			{
				sameEnds[c1]++;
			
			}
				
			else
			{
				inHash[c1]++;
				outHash[c2]++;
			}
		}
		allSame = false;
		for(int k=0;k<n;k++)
		{
			if(sameEnds[k]!=0)
			{
				if(sameEnds[k] == n)
					allSame = true;
				break;
			}
		}
		
		
		if(allSame)
			printf("Ordering is possible.\n");
		else
			possible(inHash,outHash,sameEnds);
	}
}

bool possible(int *inHash,int *outHash, int *sameEnds)
{
	int oddCount=0,d;
	bool notPossible = false;
	
	for(int k=0;k<26;k++)
	{
			if(inHash[k]>outHash[k])
				d= (inHash[k]-outHash[k]);
			else
				d = (outHash[k]-inHash[k]);
				
			if(sameEnds[k]>0)
			{
				
				if(!(inHash[k]!=0 && outHash[k]!=0 && d<=1))
				{
					notPossible = true;
					
					break;
				}
			}
			oddCount += d;			
	}
	if(oddCount<=2 && notPossible==false)
		printf("Ordering is possible.\n");
	else
		printf("The door cannot be opened.\n");
}










