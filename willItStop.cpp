#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	unsigned long long int input;
	cin>>input;

	if((input & (input-1)))
			cout<<"NIE"<<endl;
	else
			cout<<"TAK"<<endl;
	return 0;
}
