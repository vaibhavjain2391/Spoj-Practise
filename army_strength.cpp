#include<iostream>
using namespace std;
int main()
{
	int test_cases,godLen,mechLen,gMax,mMax,strength;
	cin>>test_cases;
	for(int k=0;k<test_cases;k++)
	{
		cin>>godLen;
		cin>>mechLen;
		gMax = 0;
		mMax = 0;
		for(int g=0;g<godLen;g++)
		{
			cin>>strength;
			if(strength > gMax)
				gMax= strength;
		}
		for(int m=0;m<mechLen;m++)
		{
			cin>>strength;
			if(strength > mMax)
				mMax= strength;
		}
		if(gMax >= mMax)
			cout<<"Godzilla"<<endl;
		
		else
			cout<<"MechaGodzilla"<<endl;
	}
	return 0;
}
