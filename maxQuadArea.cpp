//Using Brahmagupta's Formula. Area will be max for cyclic quadilateral(check). http://en.wikipedia.org/wiki/Brahmagupta's_formula

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	double s,area,a,b,c,d;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b>>c>>d;
		s=(a+b+c+d)/2;
		area = (s-a)*(s-b)*(s-c)*(s-d);
		area = sqrt(area);
		cout<<fixed<<setprecision(2)<<area<<endl;
	}
	return 0;
}
