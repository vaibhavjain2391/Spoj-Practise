//http://www.cprogramming.com/tutorial/stl/stlmap.html
//http://stackoverflow.com/questions/4844886/how-to-loop-through-a-c-map
//http://www.spoj.com/problems/CLONE/

#include<iostream>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	int n, m;
	char *str= new char[22];
	scanf("%d%d",&n,&m);
	map<string,int> dna;
	map<string,int>::iterator it_type;
	int *totCopies = new int[20000]; 
	while(n!=0 && m !=0)
	{
		for(int i=0;i<n;i++)
		{
			totCopies[i]=0;
			scanf("%s",str);
			if(dna.find(str) == dna.end())
				dna[str]=0; //first entry
			else
				dna[str]++;
			
		}
		for(it_type = dna.begin(); it_type != dna.end(); it_type++) 
		{
			totCopies[it_type->second]++;
		}	
		for(int i=0;i<n;i++)
		{
			printf("%d\n",totCopies[i]);
		}
		
		dna.clear();
		scanf("%d%d",&n,&m);
	}
	
}
