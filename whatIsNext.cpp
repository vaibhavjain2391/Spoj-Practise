#include<iostream>
using namespace std;
int main()
{
	int a1,a2,a3;
	cin>>a1>>a2>>a3;
	int result;
	
	while(!(a1==0 && a2==0 && a3==0))
	{
		if((a2-a1) == (a3-a2))
		{
			result = a3 + a2-a1 ;
			cout<<"AP "<<result<<endl;
		}
		else
		{
			result= a3 * (a2/a1);
			cout<<"GP "<<result<<endl;
		}
		cin>>a1>>a2>>a3;
	}
}
