#include<iostream>
using namespace std;
int minSteps(int a, int b, int c);
int main()
{
	int t,a,b,c,result;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b>>c;
		if(c==0)
			cout<<0<<endl;
		else
		{
			result= minSteps(a,b,c);
			cout<<result<<endl;
		}
		
	}
	return 0;
}


//some cases are not considered ..thats y getting wa for ex. : Answer for 10 7 6 is 6 
int minSteps(int a, int b, int c)
{
	if(a==c || b==c)
		return 1;
	
	if(a<c && b<c)
		return -1;
	
	int result = -1,tmp;
	
	if(a>c && b>c)
	{
		if(a<b){
			tmp = a;
			a=b;
			b=tmp;
		}
		
		tmp = a-b;
		tmp = b - tmp;
		if(a-tmp == c)
			result = 6;
	}
	if(a>c)
	{
		
		if(((a-c)%b) == 0)
		{
			result = ((a-c)/b)*2; //1 + (2*x-1) since, no need to throw away last mug
		}
		else if(c%b == 0)
		{
			result = 2* (c/b);
		}
	}
	else
	{
		if(((b-c)%a) == 0)
		{
			result = ((b-c)/a)*2;
		}
		else if(c%a == 0)
		{
			result = 2* (c/a);
		}
	}
	return result;	
}




