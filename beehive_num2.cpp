//beehive_num is giving time limit exceeded output.Tryping out another apporach.

#include<iostream>
using namespace std;
bool bSearch(unsigned long *store, int start, int end, unsigned long number);
int main()
{
	unsigned long number,maxNo = 1000000000;
	
	unsigned long tmp;
	unsigned long value;
	//int storeSize = 1;

	cin>>number;
	while(number!=-1)
	{
		if(number == 1 || number == 7)
			cout<<"Y"<<endl;
		
