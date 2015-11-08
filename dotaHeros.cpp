#include<iostream>
using namespace std;
int main()
{
	int t,n,m,d,h,damageControlled;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m>>d;
		damageControlled = 0;
		for(int k=0;k<n;k++)
		{
			cin>>h;
			damageControlled += h/d;
			if(h%d==0)
			{	
				damageControlled -= 1;		
			}
		}
		if(damageControlled >= m)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
