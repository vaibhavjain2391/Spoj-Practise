#include<iostream>
using namespace std;
void filllucky(int *lucky, int slen);
int main()
{
	int n;
	int sLen = 35000;
	int lucky[sLen];
	filllucky(lucky, sLen);
	scanf("%d",&n);
	while(n!=0)
	{
		printf("%d\n",lucky[n-1]);
		scanf("%d",&n);
	}
	return 0;
}

void filllucky(int *lucky, int slen)
{
	int index, count;
	for(int i=0;i<slen;i++)
		lucky[i]=1;
	
	lucky[0]=2;
	index=1;
	for(int k=3;k<slen;k+=2)
	{
		if(lucky[k])
		{
			lucky[index++]=k;
			
			count=0;
			for(int i=k+2;i<slen;i+=2)
			{
				if(lucky[i])
				{
					count++;
					if(count==k)
					{
						lucky[i]=0;
						count=0;
					}
				}
				
			}
		}
	}
}













