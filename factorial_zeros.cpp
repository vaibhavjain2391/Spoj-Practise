#include<iostream>
using namespace std;
unsigned fact_zeros(unsigned number);
int main()
{
	int tot_cases;
	cin>>tot_cases;
	unsigned number, result;
	for(int i=0;i<tot_cases;i++)
	{
		cin >> number;
		result = fact_zeros(number);
		cout<<result<<endl;
	}
	return 0;
	
}

unsigned fact_zeros(unsigned number)
{
	unsigned divisor = 5, result =0;
	while(divisor <= number)
	{
		result = result + number/divisor;
		divisor = divisor*5;
	}
	return result;
}
