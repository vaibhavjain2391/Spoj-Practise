#include<iostream>
using namespace std;
int lastDigit(int a, unsigned long b);
int main()
{
	int tot_cases,a;
	unsigned long b;
	
	cin>>tot_cases;
	
	for(int i=0;i<tot_cases;i++)
	{
		cin>>a>>b;
		int result = lastDigit(a,b);
		cout<<result<<endl;
	}
}

int lastDigit(int a, unsigned long b)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;
		
	int totDistinct=1, history[10];
	
	int firstDig = a%10;
	int curDig = (firstDig*a)%10;
	
	history[0]=firstDig;
	
	while(firstDig != curDig)
	{
		history[totDistinct]=curDig;
		totDistinct++;
		curDig = (curDig*a)%10;
		
	}	
	int index = b%totDistinct;
	if(index == 0)
		return history[totDistinct-1];
	else
		return history[index-1];
}










