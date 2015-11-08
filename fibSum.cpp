#include<iostream>
using namespace std;
void matpow(unsigned long long **mat,int n);
unsigned long long modVal=1000000007;

/*

at first try to write the first few fibo numbers:
0  1  1  2  3  5  8  13  21  34  55

now write the sum of fibo numbers from 0 to i:
0  1  2  4  7  12  20  33  54

look for a pattern in these numbers. Do you see it?!!

note that sum(x) = fib(x+2)-1

*/
int main()
{
	int t,n,m;
	cin>>t;
	unsigned long long sum1,sum2;
	unsigned long long **mat = new unsigned long long *[2];
	for(int i=0;i<2;i++)
		mat[i]=new unsigned long long[2];
	
	long long result;
	for(int i=0;i<t;i++)
	{
		
		cin>>n>>m;
		mat[0][0]=1;
		mat[0][1]=0;
		mat[1][0]=0;
		mat[1][1]=1;
		
		
		matpow(mat, n);
		sum1 = mat[0][0]-1; //finding sum(n-1);
		
		mat[0][0]=1;
		mat[0][1]=0;
		mat[1][0]=0;
		mat[1][1]=1;
		
		matpow(mat,m+1); //sum(m) = matpow(m+2 -1)
		sum2 = mat[0][0]-1;
	
		result=sum2-sum1;
		if(result<0)
			result += modVal;
		result = result%modVal;
		cout<<result<<endl;
		
	}
}
void matpow(unsigned long long **mat,int n)
{
	if(n<1)
		return;
		
	unsigned long long tmp;
	if(n>1)
	{
		matpow(mat, n/2);
	
		//	[a b | c d ] * 	[a b | c d ] 
	
		unsigned long long bSquare = (mat[0][1])*(mat[0][1]);;
		if(bSquare >= modVal)
			bSquare = bSquare%modVal;
		
		tmp = (mat[0][0]*mat[1][0]);
		if(tmp>= modVal)
			tmp = tmp%modVal;
		
		mat[0][1]= (mat[0][1]*mat[1][1]);
		if(mat[0][1] >= modVal)
			mat[0][1]= mat[0][1]%modVal;
		
		mat[0][1] += tmp;	
		if(mat[0][1] >= modVal)
			mat[0][1]= mat[0][1]%modVal;
			
			
		mat[1][0] = mat[0][1];
		
		tmp = (mat[1][1]*mat[1][1]);
		if(tmp>= modVal)
			tmp = tmp%modVal;
		
		mat[1][1] = (bSquare + tmp);
		if(mat[1][1] >= modVal)
			mat[1][1]= mat[1][1]%modVal;
			
			
		tmp = (mat[0][0])*(mat[0][0]);
		if(tmp>= modVal)
			tmp = tmp%modVal;
		
		mat[0][0] =tmp + bSquare;
		
		if(mat[0][0] >= modVal)
			mat[0][0]= mat[0][0]%modVal;
		
	}
	if(n%2 != 0)
		{
			tmp = mat[0][1];
			mat[0][1] = mat[0][0];
			mat[1][0]= mat[0][1];
			mat[1][1] = tmp;
			mat[0][0] = tmp + mat[0][0];
			if(mat[0][0] >= modVal)
				mat[0][0] = mat[0][0]%modVal;
		}	
}

















