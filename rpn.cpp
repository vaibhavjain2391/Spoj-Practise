#include<iostream>
using namespace std;
int main()
{
	char ops[200];
	char x, input[400];
	int tot_cases,index,count;
	cin>>tot_cases;
	for(int i=0;i<tot_cases;i++)
	{
		index=0,count=0;
		cin>>input;
		while(input[index])
		{
			x= input[index];
			if(x=='(')
			{
				//do nothing
			}
			
			else if(x==')')
			{
				cout<<ops[count-1];
				count--;
			}
			else if(x<='z' && x>='a')
				cout<<x;
			
			else
			{
				ops[count]=x;
				count++;	
				
			}
			index++;
		}
		cout<<endl;
	}
}
