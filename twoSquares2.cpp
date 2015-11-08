//Accepted

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool possible(unsigned long long number);
int main()
{
	int c;
	cin>>c;
	unsigned long long number;
	for(int k=0;k<c;k++)
	{
		cin>>number;
		if(possible(number))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

bool possible(unsigned long long number)
{
		
	if(number==0 || number==1)
		return true;
	

	unsigned long long rIndex = sqrt(number);
	if(rIndex*rIndex == number)
		return true;
	
	unsigned long long lIndex = 1;
	unsigned long long sum;
	while(lIndex <= rIndex)
	{
		sum = (lIndex*lIndex) + (rIndex*rIndex);
		if(sum == number)
		{
			return true;
		}
		else if(sum < number)
			lIndex++;
		else
			rIndex--;
	}
	return false;
}



























