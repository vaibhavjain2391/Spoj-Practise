#include<iostream>
using namespace std;
int main()
{
	int sum=0,number,tmp;
	bool considerNext=true;
	for(int i=0;i<10;i++)
	{
		cin>>number;		
		if(considerNext)
		{
			tmp = sum + number;
			if(tmp<=100)
				sum=tmp;
			else 
			{
				if((tmp-100) <= (100 - sum))
					sum = tmp;
				considerNext=false;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
