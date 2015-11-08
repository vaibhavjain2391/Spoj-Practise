#include<iostream>
using namespace std;
int minCards(float input);
int main()
{
	float input;
	cin>>input;
	int res;
	
	while(input != 0.00)
	{
		res = minCards(input);
		cout<<res<<" card(s)"<<endl;
		cin>>input;
	}
	return 0;
}


int minCards(float input)
{
	int index=2;
	float x =1/float(index);
	while(input>x)
	{
		index++;
		x+= (1/float(index));	
		//cout<<x<<endl;
	}
	return index-1;
}
