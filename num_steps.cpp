#include<iostream>
using namespace std;
int findPoint(int x, int y);
int main()
{
	int tot_cases, x, y,result;
	cin>>tot_cases;
	for(int i=0;i<tot_cases;i++)
	{
		cin>>x>>y;
		result = findPoint(x,y);
		if(result==-1)
			cout<<"No Number"<<endl;
		else
			cout<<result<<endl;
	}
}

int findPoint(int x, int y){
	
	int yp1,yp2;
	if((x>y && (x-y)>2) || (x<y ))
		return -1;
		
	if(x%2 == 0 && y%2==0)
	{
		yp1= y*2;
		yp2= yp1+2;
		
		if(x==y)
			return yp1;
		if(x>y)
			return yp2;
	}
	
	else if(x%2!=0 && y%2!=0)
	{
		yp1= y*2-1;
		yp2= y*2+1;
		
		if(x>y)
			return yp2;
		if(x==y)
			return yp1;
	}
	
	return -1;
}








