#include<iostream>
using namespace std;
bool bSearch(unsigned long *store, int start, int end, unsigned long number);
int main()
{
	unsigned long number,maxNo = 1000000000;
	unsigned long store[20000];
	store[0]=1;
	unsigned long tmp=6;
	unsigned long value=7;
	int storeSize = 1;
	while(value <= maxNo)
	{
		store[storeSize]=value;
		tmp= tmp+6;
		value+= tmp;
		storeSize++;
	}
	for(int k=0;k<20;k++)
		cout<<store[k]<<endl;
	//cin>>number;
	number = -1;
	while(number!=-1)
	{
		if(number==1 || ((number-1)%6==0 && bSearch(store, 0, storeSize-1,number)))
			cout<<"Y"<<endl;
		else
		 	cout<<"N"<<endl;
		cin>>number;
	}
	return 0;
	
}


bool bSearch(unsigned long *store, int start, int end, unsigned long number)
{
	if(start>end)
		return false;
	
	int mid = (start+end)/2;
	if(store[mid] == number)
		return true;
	
	else if(store[mid]> number)
		return bSearch(store, start, mid-1, number);
	
	else
		return bSearch(store, mid+1, end, number);
}






















