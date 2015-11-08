#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,d,v;
	cin>>t;
	bool possible = true;
	double tmp, result;
	for(int i=0;i<t;i++)
	{
		possible = true;
		scanf("%d%d",&d,&v);
		tmp = (d*9.806)/(v*v);
		if(tmp>1 || tmp<-1)
			possible = false;
		else
		{
			result = 0.5*(asin(tmp));
			tmp = 180.0/(acos(0.0)*2); 
			result = result*tmp;
			if(result<0 || result>45)
				possible = false;
		}
		if(!possible)
			printf("Scenario #%d: -1\n",i+1);
		else
			printf("Scenario #%d: %.2f\n",i+1,result);
		
	}
	return 0;
}
