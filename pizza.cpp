#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char *x=new char[5];
	int countbyTwo=0,countThreeByFour=0, countOneByFour=0,result;
	for(int i=0;i<n;i++)
	{
		
		cin>>x;
		if(x[0]=='1')
		{
			if(x[2]=='2')
			{
				countbyTwo++;
			}
			else
				{
					countOneByFour++;
				}
		}
		else
		{
			countThreeByFour++;	
		}
			
	}
	result =1 + countThreeByFour + countbyTwo/2;
	countOneByFour = countOneByFour - countThreeByFour;
	if(countbyTwo%2 != 0)
		{
			result += 1;
			countOneByFour -= 2;
		}
	if(countOneByFour > 0)
		{
			result += countOneByFour/4;
			if(countOneByFour%4 != 0)
				result += 1; 
		}
	cout<<result<<endl;	
	
}
