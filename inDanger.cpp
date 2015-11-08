#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	char str[5];
	cin>>str;
	unsigned long tmp, number,result;
	while(!(str[0]=='0' && str[1]=='0' && str[3]=='0'))
	{
		number = str[0]-'0';
		number = number*10 + (str[1]-'0');
		tmp = pow(10, str[3]-'0');
		number = number*tmp;
		
		tmp = log2(number);
		tmp = pow(2, tmp);
		result = 2*(number - tmp) + 1;
		cout<<result<<endl;
		cin>>str;
	}
	return 0;
}

