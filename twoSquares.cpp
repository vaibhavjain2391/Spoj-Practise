//Giving compilation issues in ideone !

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool possible(long long number, vector<long long> sqStore, long long len);
long long bsearch(long long number, vector<long long> store, long long left, long long right);
int main()
{
	int c;
	cin>>c;
	long long number;
	vector<long long> sqStore;
	unsigned long long index=2, sum=1, tmp =1000000000000 ;
	while(sum<tmp)
	{
		sqStore.push_back(sum);
		sum = index*index;
		index++;
	}
	
	index--;
	for(int k=0;k<c;k++)
	{
		cin>>number;
		if(possible(number,sqStore,index))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

bool possible(long long number, vector<long long> sqStore, long long len)
{
	
	
	if(number==0 || number==1)
		return true;
	

	long long rIndex = bsearch(number, sqStore, 0 , len-1);
	
	if(sqStore[rIndex]==number)
		return true;
	long long lIndex = 0;
	long long sum;
	while(lIndex <= rIndex)
	{
		sum = sqStore[lIndex]+sqStore[rIndex];
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

long long bsearch(long long number, vector<long long> store, long long left, long long right)
{
	if(left>right || left <0)
		return -1;
	
	long long mid = (left+right)/2;
	if(store[mid] == number)
		return mid;
	
	if(store[mid] > number)
	{
		if(store[mid-1] < number)
			return mid-1;
		else
			return bsearch(number, store, left, mid-1);		
	} 
	else
	{
		return bsearch(number, store, mid+1, right);
	}
}









































