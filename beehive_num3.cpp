#include<iostream>
#include<math.h>
using namespace std;
bool applyRule(unsigned long number);
int main()
{
	unsigned long number;
	
	//1 3 6 10 15 21 ...
	//series : 1, 7, 19, 37, 61 ... ==> 3n(n-1) + 1
	
	
	unsigned long index=2;
	unsigned long value=1;
	
	cin>>number;
	while(number!=-1)
	{
		if(number==1 || ((number-1)%3==0 && applyRule(number)))
			cout<<"Y"<<endl;
		else
		 	cout<<"N"<<endl;
		cin>>number;
	}
	return 0;
	
}


bool applyRule(unsigned long number)
{
	/*unsigned long tmp = (number-1)/3;
	
	unsigned long x = sqrt(tmp);
	if((x*(x+1)) == tmp)
		return true;
	else
	 	return false;*/
	
	unsigned long tmp = 4*number-1;
	if(tmp%3 == 0)
	{
		tmp=tmp/3;
		unsigned long x = sqrt(tmp);
		if(x*x == tmp)
			return true;
	}
	return false;
	 	
}




















