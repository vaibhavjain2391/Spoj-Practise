#include<iostream>
using namespace std;
void maxTime(int h, int a);
int main()
{
	int t,h,a;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>h>>a;
		maxTime(h,a);
	}
	return 0;
}

void maxTime(int h, int a)
{
	int time = 1;
	h = h+3;
	a = a+2;
	bool case1=true,case2=true;
	while(case1 || case2)
	{
		if(a>10 && h>5)
		{
			while(a>10 && h>5)
			{
				time+=2;
				a=a-8;
				h=h-2;
				case1 = true;
			}
		}
		else
		{
			case1=false;
		}
		if(h>20)
		{
			time+=2;
			a=a+7;
			h=h-17;
			case2 = true;
		}
		else
			case2=false;
		
	}
	cout<<time<<endl;
}













