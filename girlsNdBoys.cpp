
#include<iostream>
using namespace std;
int regularity(int max, int min);
int main()
{
	int g, b;
	cin>>g>>b;
	while(g!=-1 && b!=-1)
	{
		if(g==0 && b==0)
			cout<<0<<endl;
		else if(g==0)
			cout<<b<<endl;
		else if(b==0)
			cout<<g<<endl;
		else if(g>b)
			cout<<regularity(g,b)<<endl;
		else
			cout<<regularity(b,g)<<endl;
		cin>>g>>b;
	}
	return 0;
}

int regularity(int max, int min)
{
	if(max==min || max==(min+1))
		return 1;
	
	min = min+1;
	int result=max/min;
	if((max % min)== 0)
		return result;
	else
		return (result + 1);
}
