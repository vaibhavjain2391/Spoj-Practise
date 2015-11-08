#include<iostream>
#include<math.h>
using namespace std;
unsigned addRev(unsigned num1 , unsigned num2);
int main()
{
	int N;
	cin >> N;
	unsigned x,y,result;
	for(int i=0;i<N;i++)
	{
		cin >> x;
		cin >>y;
		result = addRev(x, y);
		cout<<result<<endl;
	}
	return 0;
}


unsigned addRev(unsigned num1 , unsigned num2)
{
	if(num1==0 || num2 == 0)
	{ 
		if(num1 == 0) 
			return num2;
		else if(num2 == 0)
			return num1;
	}
	
	unsigned result = 0,tmp=10;
	int lenNum1 = 1, lenNum2 =1;
	
	while(num1 >= tmp)
	{
		tmp=tmp*10;
		lenNum1++;
	}
	
	tmp =10;
	while(num2 >= tmp)
	{
		tmp = tmp*10;
		lenNum2++;
	}
	
	int remainder = 0;
	while(lenNum1>0 || lenNum2>0)
	{
		tmp=0;
		
		if(lenNum1 > 0)
		{
	    	tmp= (int(num1/(pow(10,lenNum1-1))))%10;
	    }
	    
	    if(lenNum2 > 0)
	    {
	    	tmp = tmp + (int(num2/(pow(10, lenNum2-1))))%10;
	    }
	    	
		tmp =  tmp + remainder;
		
		if(tmp>=10)
		{
			remainder = tmp/10;
			tmp = tmp%10;
		}
		else
		{
			remainder = 0;
		}
		
		if(result == 0)
			result = tmp;
			
		else
			result = result*10 + tmp;
		
		//cout<<result <<endl;
		lenNum1--; lenNum2--;
		
	}
	
	if(remainder > 0)
	{
		if(result == 0)
			result = remainder;
			
		else
			result = result*10 + remainder;
		
	}
	
	return result;
		
}



















































