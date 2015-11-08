#include<iostream>
#include<string.h>
using namespace std;
void add(char *s1,int len1, char *s2,int len2, char *result);
void sub(char *result, int len, int number);

// Logic : Answer : N+(N-2), N>=3 ; N , N<3
int main()
{
	char input[102];
	char result[103];
	int len;
	while(cin>>input)
	{
		len = strlen(input);
		if(len == 1 && ((input[0]-'0')<=2))
		{
			if(input[0]=='0')
				cout<<0<<endl;
			else if(input[0]=='1')
				cout<<1<<endl;
			else if(input[0]=='2')
				cout<<2<<endl;
		}
		else
		{
			add(input,len, input,len, result); //N+N
			sub(result,len+1,2);
			if(result[0] != '0')
			cout<<result[0];
			for(int i=1;i<=len;i++)
			{
				cout<<result[i];
			}	
			cout<<endl;
		}
		
	}
}

void sub(char *result, int len, int number)
{
	//I am not handling all the subtraction cases as it is not needed for this program
	//1. no is single digit, 2. result>number
	 
	bool carryOver = false;
	int index = len-1,tmp;
	while(index>=0)
	{
		tmp = (result[index]-'0');
		if(carryOver)
			tmp--;
		
		if(tmp<number)
		{
			carryOver = true;
			tmp = tmp + 10;
			result[index] = (tmp-number)+'0';
		}
		else
		{
			result[index]=(tmp-number)+'0';
			carryOver=false;
		}
		if(!carryOver)	
			break;
		index--;
		number=0;
	}
}

void add(char *s1,int len1, char *s2,int len2, char *result)
{
	if(len1==len2) //which is my case..not making it general right now
	{
		for(int k=0;k<len2;k++)
		{
			result[k+1]=s2[k];
		}
		result[len2+1]='\0';
				
		int right = len1,remainder =0,tmp;
		for(int index = len1-1;index>=0;index--)
		{
			tmp = (s1[index]-'0') + remainder + (result[right]-'0');
			result[right]=(tmp%10) + '0';
			remainder = tmp/10;
			right--;
		}
		
		if(remainder!=0)
		{
			result[0]=(remainder%10) + '0';
			//remainder = remainder/10;
		}
		else
			result[0]='0';
	
		/*if(result[0] != '0')
			cout<<result[0];
		for(int i=1;i<=len1;i++)
		{
			cout<<result[i];
		}	
		cout<<endl;*/
		
	}
}

















