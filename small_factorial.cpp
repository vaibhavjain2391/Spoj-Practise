#include<iostream>
using namespace std;
void fill_factValues(int **a,int a_size,int* len);
int main()
{
	int **a;
	int maxFactLen=300;
	a= new int*[100];
	for(int i=0;i<100;i++)
		a[i]=new int[maxFactLen];
	
	for(int k=0;k<100;k++)
		for(int j=0;j<maxFactLen;j++)
			a[k][j]=0;
		
		
	int len[100]; 
	for(int i=0;i<100;i++)
		len[i]=1;
	
	fill_factValues(a,100,len);
	int tot_cases,number;
	cin>>tot_cases;
	for(int i=0;i<tot_cases;i++)
	{
		cin>>number;
		for(int k=len[number-1]-1;k>=0;k--)
			cout<<a[number-1][k];	
		cout<<endl;
	}
	
	for(int i=0;i<100;i++)
		delete a[i];
	delete a;
	
	return 0;
	
}

void fill_factValues(int **a,int a_size,int* len)
{
	len[0]= 1;
	a[0][0]=1;
	int tmp1, tmp2, curLen,remainder;
	for(int i=2;i<=100;i++)
	{
		//multiply(i-1,a[i-2],a[i-1],len);
		
		for(int k=0;k<len[i-2];k++)
		{
			tmp1 = a[i-2][k]*i;
			remainder =0;
			curLen = k;
			while(tmp1>0)
			{
				tmp2 = tmp1%10;
				tmp1= tmp1/10;
				
				
				a[i-1][curLen] += tmp2 + remainder;
				remainder = 0;
				if( a[i-1][curLen] >= 10)
				{
					remainder = a[i-1][curLen]/10;
					a[i-1][curLen] = a[i-1][curLen]%10;
				}
				
				curLen++;
				
			}
			
			while(remainder>0 )
			{
				a[i-1][curLen] +=  remainder;
				remainder = 0;
				if(a[i-1][curLen] >= 10)
				{
					remainder = a[i-1][curLen]/10;
					a[i-1][curLen] = a[i-1][curLen]%10;
				}
				curLen++;
			}
			if(curLen > len[i-1])
				len[i-1] = curLen;
		}
		
			
	}
	
}






















