//Ginving TLE, use segmentations Tree 

#include<iostream>
using namespace std;
bool validBrc(char *store,int len);
int main()
{
	int len,ops,k,opCount,clCount;
	
	for(int x=0;x<10;x++)
	{
		opCount=0,clCount=0;
		printf("Test %d:\n",x+1);
		scanf("%d",&len);
		char *store= new char[len+1];
		scanf("%s",store);
		for(int i=0;i<len;i++)
		{
			if(store[i]=='(')
				opCount++;
			else
				clCount++;
		}
		scanf("%d",&ops);
		for(int i=0;i<ops;i++)
		{
			scanf("%d",&k);
			if(k==0)
			{
				if(opCount==clCount && validBrc(store, len))
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				if(store[k-1]=='(')
				{	
					clCount++;
					opCount--;
					store[k-1]=')';
				}
				else
				{
					clCount--;
					opCount++;
					store[k-1]='(';
				}
			}
		}
		delete store;
	}
	return 0;
}


bool validBrc(char *store,int len)
{
	int totOp = 0;
	bool valid = true;
	for(int i=0;i<len;i++)
	{
		if(store[i]=='(')
		{
			totOp++;
		}
		else
		{
			if(totOp==0)
			{
				valid = false;
				break;
			}
			else
				totOp--;
		}
	}
	if(valid && totOp == 0)
		return true;
	else
		return false;
}

















