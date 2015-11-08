#include<iostream>
using namespace std;
int main()
{
	int t,n,prev;
	scanf("%d",&t);
	char *str = new char[5];
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		scanf("%s",str);
		if(str[0]=='h')
			prev = 0;
		else
			prev = 1;
		
		for(int j=1;j<n;j++)
		{
			scanf("%s",str);
			if(str[0]!='h')
			{
				if(prev == 1)
					prev = 0;
				else
					prev = 1;
			}
		}
		
		if(prev==1)
			printf("lxh\n");
		else
			printf("hhb\n");
	}
	return 0;
}
