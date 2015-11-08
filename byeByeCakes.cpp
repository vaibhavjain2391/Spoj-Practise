#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a1,b1,c1,d1,a2,b2,c2,d2,tmp,maxDiv;
	cin>>a1>>b1>>c1>>d1>>a2>>b2>>c2>>d2;

	while(a1!=-1)
	{
		tmp = ceil(double(a1)/double(a2));
		maxDiv=tmp;
		
		tmp = ceil(double(b1)/double(b2));
		if(tmp > maxDiv)
			maxDiv=tmp;
			
		tmp = ceil(double(c1)/double(c2));
		if(tmp > maxDiv)
			maxDiv=tmp;
		
		tmp = ceil(double(d1)/double(d2));
		if(tmp > maxDiv)
			maxDiv=tmp;
		
		cout<<(maxDiv*a2)-a1<<" ";
		cout<<(maxDiv*b2)-b1<<" ";
		cout<<(maxDiv*c2)-c1<<" ";
		
		/*tmp = (maxDiv*b2)-b1;
		if(tmp>0)
			cout<<tmp<<" ";
		else
			cout<<0<<" ";
			
		tmp = (maxDiv*c2)-c1;
		if(tmp>0)
			cout<<tmp<<" ";
		else
			cout<<0<<" ";*/
			
		cout<<(maxDiv*d2)-d1<<endl;
		
		cin>>a1>>b1>>c1>>d1>>a2>>b2>>c2>>d2;
	}
	return 0;
}










