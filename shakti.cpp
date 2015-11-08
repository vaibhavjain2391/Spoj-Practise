#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	unsigned long long num;
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&num);
		if(num%2 ==0 )
			printf("Thankyou Shaktiman\n");
		else
			printf("Sorry Shaktiman\n");
	}
	return 0;
}
