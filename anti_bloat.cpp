#include<iostream>
#include<string.h>
using namespace std;
int convertStringToInt(char *input,int len);
int main()
{
	int tot_cases,a1,a2,a3,result;
	cin>>tot_cases;
	char input[20];
	char symbol;
	for(int i=0;i<tot_cases;i++)
	{
		cin>>input;
		a1=convertStringToInt(input,strlen(input));
		cin>>symbol;
		
		if(a1==-1)
		{
			cin>>a2;
			cin>>symbol;
			cin>>a3;
			a1 = a3-a2;
		}
		else
		{
			cin>>input;
			a2=convertStringToInt(input,strlen(input));
			cin>>symbol;
			if(a2==-1)
			{
				cin>>a3;
				a2=a3-a1;
			}
			else
			{
				cin>>input;
				a3= a1+a2;	
			}
		}
		
		cout << a1 <<" + "<<a2<<" = "<<a3<<endl;
	}
	
}

int convertStringToInt(char *input,int len)
{
	int result=0;
	for(int i=0;i<len;i++)
	{
		if(input[i]<='9' && input[i]>='0')
			result= result*10 + (input[i]-'0');
		else
			return -1;
	}
	return result;
}




















