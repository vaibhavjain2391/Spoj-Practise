#include<iostream>
using namespace std;
int main()
{
	char *s = "23 march 1991";
	char month[10];
	int date, year;
	sscanf(s,"%d %s %d",&date,month,&year);
	cout<<date<<"\t"<<month<<"\t"<<year<<endl;
	return 0;
}
