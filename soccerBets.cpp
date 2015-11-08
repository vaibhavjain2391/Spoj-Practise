//http://www.cprogramming.com/tutorial/stl/stlmap.html
//http://stackoverflow.com/questions/4844886/how-to-loop-through-a-c-map

//both soccerBets1 and soccerBets2 give right answer


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
	map<string,int> teamWins;
	map<string,int> winCount;
	map<string,int>::iterator it_type;

	for(int i=0;i<t;i++)
	{
		for(int j=0;j<16;j++)
		{
			scanf("%s%s%d%d",str1,str2,&g1,&g2);
			
			if(g1>g2)
			{
				if(teamWins.find(str1) == teamWins.end())
				{
					teamWins[str1]=1; //first entry
					winCount[str1]=1;
				}
				else
				{
					teamWins[str1]++;
					winCount[str1]++;
				}
			}
			else
			{
				if(teamWins.find(str2) == teamWins.end())
				{
					teamWins[str2]=1; //first entry
					winCount[str2]=1;
				}
				else
				{
					teamWins[str2]++;
					winCount[str2]++;
				}
			}
			
		}
		for(it_type = teamWins.begin(); it_type != teamWins.end(); it_type++) 
		{
			if((it_type->second)==4)
			{
				if((winCount.find(it_type->first))->second == 4)
				{
					cout<<it_type->first<<endl;
					break;
				}
			}
			
		}	
		
		teamWins.clear();
		winCount.clear();
	}
	
}
