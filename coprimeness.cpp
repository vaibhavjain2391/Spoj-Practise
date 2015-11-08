#include<iostream>
using namespace std;
/*unsigned long long gcd(unsigned long long a,unsigned long long b)
{
  if (a == b)
        return a;
 
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}*/

int gcd(long long int a,long long b) 
{ return (b==0?a:a>b?gcd(b,a%b):gcd(a,b%a)); } 

int main()
{
	int t;
	unsigned long long tmp,number;
	bool resFound;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&number);
		
		for(tmp=number/2;tmp>=1;tmp--) 
		{ 
			if(gcd(number,tmp)==1)
			{ 
				printf("%llu\n",tmp);
				break; 
			} 
		} 
	}
		
		
		/*resFound=false;
		tmp = number/2;
		
		//even
		if(tmp*2 == number)
		{
			for(tmp=tmp-1;tmp>1;tmp-=2)
			{
				if(number%tmp!=0 && gcd(number, tmp) == 1)
				{
					printf("%llu\n",tmp);
					resFound=true;
					break;
				}
			}
			if(!resFound)
				printf("1\n");
		}
		else
			printf("%llu\n",tmp);	 //odd case
	
	}	*/
	return 0;
}
