#include<iostream>
using namespace std;
int winner(int n, int d);
int josephusIteration(int n,int k);
int main()
{
	int n,d,result;
	cin>>n>>d;
	while(n!=0)
	{
		//result  = winner(n,d);
		result  = josephusIteration(n,d);
		cout<<n<<" "<<d<<" "<<result<<endl;
		cin>>n>>d;
	}
	return 0;
}

int winner(int n, int d)
{
	if(n==1)
		return 1;
	else
	{
		int tmp=  (winner(n-1,d) + (d-1))%n + 1;
		return tmp;
	}
}

int josephusIteration(int n,int k) {
	int a=1;
	for(int i=1;i<=n;i++) {
		a=(a+k-1)%i+1;
	}
	return a;
}


