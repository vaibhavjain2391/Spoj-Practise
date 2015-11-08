#include<iostream>
using namespace std;
int main()
{
	int a, d, aMin, dMin, dSecondMin, number;
	cin>>a;
	cin>>d;
	while(a!=0 &&d!=0)
	{
		if(d==1)
			cout<<"N"<<endl;
		else
		{
		cin>>aMin;
		for(int k=1;k<a;k++)
		{
			cin>>number;
			if(number < aMin)
				aMin=number;
		}
		cin>>dMin;
		cin>>number;
		if(number < dMin)
		{
			dSecondMin = dMin;
			dMin = number;
		}
		else
		{
			dSecondMin = number;
		}
		for(int k=2;k<d;k++)
		{
			cin>>number;
			if(number < dMin)
			{
				dSecondMin = dMin;
				dMin = number;
			}
			else if(number < dSecondMin)
			{
				dSecondMin = number;
			}
		}
		if(aMin < dSecondMin)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
		}
		cin>>a;
		cin>>d;
	}
	return 0;
}














