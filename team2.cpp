#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long a[4], tmpsq, tmp;
	int caseNo = 1;
	while(cin>>a[0])
	{
		for(int i=1;i<4;i++)
			cin>>a[i];
		
		sort(a,a+4);
		tmp= a[2]+a[3];
		cout<<"Case "<<caseNo<<": ";
		cout<<tmp<<endl;
		caseNo ++;
	}
	return 0;
}
