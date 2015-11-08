#include<iostream>
using namespace std;
int main()
{
	int long long input;
	cin>>input;
	if(input%10==0)
		cout<<2<<endl;
	else
	{
		cout<<1<<endl;
		cout<<input%10<<endl;
	}
	return 0;		
}
