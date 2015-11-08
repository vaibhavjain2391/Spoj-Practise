//http://www.cprogramming.com/tutorial/stl/stlmap.html
//http://stackoverflow.com/questions/4844886/how-to-loop-through-a-c-map


#include<iostream>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	int t,g1,g2;
	char *str1= new char[10];
	char *str2= new char[10];
	scanf("%d",&t);
	map<string,bool> teamWins;

	map<string,bool>::iterator it_type;

	for(int i=0;i<t;i++)
	{
		for(int j=0;j<16;j++)
		{
			scanf("%s%s%d%d",str1,str2,&g1,&g2);
			
			if(g1>g2)
			{
				teamWins[str2]=false;
				if(teamWins.find(str1) == teamWins.end())
					teamWins[str1]=true;
			}
			else
			{
				teamWins[str1]=false;
				if(teamWins.find(str2) == teamWins.end())
					teamWins[str2]=true;
			}
		}
	
		for(it_type = teamWins.begin(); it_type != teamWins.end(); it_type++) 
		{
			if(it_type->second)
			{
				cout<<it_type->first<<endl;
					break;
			}
		}	
		
		teamWins.clear();
		
	}
	return 0;
}
