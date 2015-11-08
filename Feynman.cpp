#include<iostream>
using namespace std;
void fill_squares(int *totSquares, int size);
int main()
{
	int size = 100;
	int totSquares[size];
	fill_squares(totSquares, size);
	int input;
	cin>>input;
	while(input != 0)
	{
		cout<<totSquares[input - 1];
		cout<<endl;
		cin>> input;
	}
	return 0;
}

void fill_squares(int *totSquares, int size)
{
	totSquares[0]=1;
	for(int i=1;i<size;i++)
	{
		totSquares[i] = (i+1)*(i+1) + totSquares[i-1];
	}
}
