#include<iostream>
using namespace std;
void printResult(char *toss);
int main()
{
	int total,current;
	cin>>total;
	char toss[45];
	for(int k=0;k<total;k++)
	{
		cin>>current;
		cin>>toss;
		cout<<current;
		printResult(toss);
	}
	return 0;
}

void printResult(char *toss)
{
	int a=0, b=0, c=0;
	
	//TTT, TTH, THT, THH, HTT, HTH, HHT and HHH
	//000, 001, 010, 011, 100, 101, 110, 111
	int count[8];
	for(int i=0;i<8;i++)
		count[i]=0;
		
	if(toss[0]=='H')
		a=1;
	else
		a=0;
		
	if(toss[1]=='H')
	{
		a=a*2 + 1;
		b=1;
	}
	else
	{
		a=a*2;
		b=0;
	}
	
	if(toss[2]=='H')
	{
		a=a*2 +1;
		b= b*2 +1;
		c=1;
	}
	else
	{
		a=a*2;
		b=b*2;
		c=0;
	}
	
	int index=3;
	while(index<40)
	{
		if(index%3 == 0)
		{
			count[a]++;
			
			if(toss[index]=='H')
			{
				a=1;
				b=b*2 +1;
				c=c*2+1;
			}
			else
			{
				a=0;
				b=b*2;
				c=c*2;
			}
			
		}
		
		else if(index%3 == 1)
		{
			count[b]++;
			
			if(toss[index]=='H')
			{
				a=a*2+1;
				b=1;
				c=c*2+1;
			}
			else
			{
				a=a*2;
				b=0;
				c=c*2;
			}
			
		}
		
		else
		{
			count[c]++;
			
			if(toss[index]=='H')
			{
				a=a*2+1;
				b=b*2 +1;
				c=1;
			}
			else
			{
				a=a*2;
				b=b*2;
				c=0;
			}
			
		}
		
		index++;
	}
	//40%3 =1
	count[b]++;
	
	for(int k=0;k<8;k++)
		cout<<" "<<count[k];
	cout<<endl;
}



















