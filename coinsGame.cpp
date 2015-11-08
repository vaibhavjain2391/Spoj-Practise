#include<iostream>
using namespace std;
int main()
{
	int k,l,m,n,tmp;
	cin>>k>>l>>m;
	
	bool winner[1000001];
	winner[0]=false;
	winner[1]=true;
	/*for(int i=2;i<1000001;i++)
	{
		if(a[i-1]==false 
	}*/
	
	if(k>l)
	{
		tmp = k;
		k=l;
		l=tmp;
	}
	for(int i=2;i<k;i++)
	{
		winner[i]=true;
		if(winner[i-1])
			winner[i]=false;
	}
	winner[k]=true;
	for(int i=k+1;i<l;i++)
	{
		winner[i]=true;
		if(winner[i-1] && winner[i-k])
			winner[i]=false;
	}
	winner[l]=true;
	for(int i=l+1;i<1000001;i++)
	{
		winner[i]=true;
		if(winner[i-1] && winner[i-k] && winner[i-l])
			winner[i]=false;
	}
	for(int i=0;i<m;i++)
	{
		cin>>n;
		if(winner[n]==true)
			cout<<"A";
		else
			cout<<"B";
	}
	cout<<endl;
	return 0;
}










