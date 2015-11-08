#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int long long test_cases, third, lastThird, sum, c1, c2, tmp, n, a, d,tmp2;
	cin>>test_cases;
	for(long long i=0;i<test_cases;i++)
	{
		cin>>third>>lastThird>>sum;
		if(third == lastThird)
		{
			n = sum/third; 
			d = 0;
			tmp = third;
		}
		else
		{
		c1 = lastThird+third;
		c2 = lastThird-third;
		
		d = c1*c2;
		tmp = 2*sum;
		tmp2 = 5*c1;
		tmp = tmp - tmp2;
		d = d/tmp;
		
		
		a = third - 2*d;
		
		n = (lastThird - third)/d + 5;
		tmp = a;
	    }
		
		cout<<n<<endl;
		for(long long k=0;k<n;k++)
		{
			cout<<tmp<<" ";
			tmp=tmp+d;
		}
		cout<<endl;
		
	}
}
