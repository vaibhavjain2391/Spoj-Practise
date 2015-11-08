#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
//const double PI = atan(1.0)*4;

int main()
{
	float PI = 3.1415926;
	int len;
	cin>>len;
	float answer;
	while(len != 0)
	{
		answer = float(len*len)/float(2*PI);
		cout << setprecision(2) << fixed << answer << endl;
		cin>>len;
	}
	return 0;
}
