#include<iostream>
#include<math.h>
using namespace std;
int modBinarySearch(unsigned *sum, int start, int end, unsigned number);
int main()
{

	unsigned sum[5000],val=1;
	int sumSize = 0;
	while(val < 10000001)
	{
		sum[sumSize++]=val;
		val+= (sumSize+1);
	}
	
	int t;
	cin>>t;
	unsigned number,result,tmp,diff,denominator,numerator;
	for(int i=0;i<t;i++)
	{
		scanf("%u",&number);
		result = modBinarySearch(sum, 0, sumSize-1, number);
		diff = number - result-1;
		//cout<<result<<endl;
		tmp = (int)sqrt(1+(8*result)) - 1;
		//cout<<tmp<<endl;
		tmp = tmp/2;
		//cout<<tmp<<endl;
		numerator = 1 + diff;
		denominator = tmp + 1 - diff; 
		cout<<"TERM "<<number<<" IS ";
		if(tmp%2!=0)
			cout<<numerator<<"/"<<denominator<<endl;
		else
			cout<<denominator<<"/"<<numerator<<endl;
	}
	return 0;
}

int modBinarySearch(unsigned *sum, int start, int end, unsigned number)
{
	if(start>end || start<0)
		return -1;
	int mid = (start+end)/2;
	if(number == sum[mid])
		return sum[mid-1];
	else if(number > sum[mid])
	{
		return modBinarySearch(sum, mid+1, end, number);
	}
	else 
	{
		if(mid==0)
			return sum[mid];
		else if(sum[mid-1] < number)
			return sum[mid-1];
		else
			return modBinarySearch(sum, start, mid-1, number);
	}
	
}
