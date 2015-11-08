#include<iostream>
using namespace std;
long long maxSum(int *store1, int *store2, int len1, int len2);
int main()
{
	int store1[10000],store2[10000];
	int len1,len2,number;
	long long result;
	cin>>len1;
	while(len1!=0)
	{
		for(int i=0;i<len1;i++)
			cin>>store1[i];
		
		cin>>len2;
		for(int i=0;i<len2;i++)
			cin>>store2[i];
			
		result = maxSum(store1,store2,len1,len2);
		cout<<result<<endl;
		cin>>len1;
	}
	return 0;
}


long long maxSum(int *store1, int *store2, int len1, int len2)
{
	int index1=0, index2=0;
	long long sum1 = 0,sum2=0, result=0;
	while(index1<len1 && index2<len2)
	{
		if(store1[index1]<store2[index2])
		{
			sum1 += store1[index1];
			index1++;
		}
		else if(store1[index1]>store2[index2])
		{
			sum2 += store2[index2];
			index2++;
		}
		else
		{
			if(sum1>sum2)
				result += sum1;
			else
				result += sum2;
				
			result += store1[index1];
			index1++;
			index2++;
			sum1=0;
			sum2=0;
		}
	}
	while(index1<len1)
	{
		sum1 += store1[index1];
		index1++;
	}
	while(index2<len2)
	{
		sum2 += store2[index2];
		index2++;
	}
	if(sum1>sum2)
		result += sum1;
	else
		result += sum2;
		
	return result;
}
















