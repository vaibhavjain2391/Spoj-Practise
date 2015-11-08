#include<iostream>
using namespace std;

long noOfRectangles(int n);
int main()
{
	int n;
	cin>>n;
	long result = noOfRectangles(n);
	cout<<result<<endl;
	return 0;
}


long noOfRectangles(int n)
{
	long res=n;
	int index=2;
	int sqIndex = index*index;
	while(sqIndex <= n)
	{
		res += ((n/index) - index +1);
		index=index+1;
		sqIndex= index*index;
	}
	return res;
}

