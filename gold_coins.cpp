#include<iostream>
using namespace std;
unsigned long maxDollar(unsigned long n, unsigned long *history);
int main()
{
	unsigned long *history=new unsigned long[10000000];
	for(unsigned int i=0;i<10000000;i++)
		history[i]=-1;
	history[0]=1; //case 1
	history[1]=2;
	unsigned long n,result;
	while(cin>>n)
	{
		if(n==0)
		{
			cout<<n<<endl;
		}
		else
		{
			result = maxDollar(n,history);
			cout<<result<<endl;
		}
		
	}
	delete history;
	return 0;
}

unsigned long maxDollar(unsigned long n, unsigned long *history)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	
	if(n==2)
		return 2;
	
	unsigned long sum=0,tmp;
	
	tmp=n/2;
	if(tmp>0 && history[tmp-1] != -1)
		sum = history[tmp-1];
	else
		sum = maxDollar(tmp,history);
		
	tmp=n/3;
	if(tmp>0 && history[tmp-1] != -1)
		sum += history[tmp-1];
	else
		sum += maxDollar(tmp,history);
		
	tmp=n/4;
	if(tmp>0 && history[tmp-1] != -1)
		sum += history[tmp-1];
	else
		sum += maxDollar(tmp,history);
	
	if(sum > n)
	{
		if(n<10000000)
			history[n-1]=sum;
		return sum;
	}
	else
	{
		if(n<10000000)
			history[n-1]= n;
		return n;
	}

}
