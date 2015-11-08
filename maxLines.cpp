#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t;
	long long int radius;
	cin>>t;
	long double result;
	for(int k=1;k<=t;k++){
		cin>>radius;
		result = radius*radius;
		result = 4*result;
		result += 0.25;
		
		cout<<"Case "<<k<<": "<<fixed<<setprecision(2)<<result<<endl;
	}
}
