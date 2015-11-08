#include<iostream>
using namespace std;
int main()
{
	long long int test_cases, number, result;
	char op='a';
	cin>>test_cases;
	for(long long int k=0;k<test_cases;k++)
	{
		cin >> number;
		result = number;
		cin>>op;
		while(op != '=')
		{
			cin >> number;			
			if(op=='+')
				result+=number;
			else if(op=='-')
				result-=number;
			else if(op=='/')
				result/=number;
			else if(op=='*')
				result*= number;
			cin>>op;
		}
		cout<<result<<endl;
	}
	return 0;
}
