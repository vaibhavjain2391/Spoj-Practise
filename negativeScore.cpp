//will do it sometime later..easy question..

#include<iostream>
#include<math.h>
using namespace std;
int segTree(int *arr, int *st, int left, int right,int index);
int *constructST(int *arr, int n);
int getSumUtil(int *st,int left, int right, int stLeft, int stRight, int stIndex);
int getSum(int *st,int arrSize,int left, int right);

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
    
 
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n", getSum(st, n, 1, 3));
 
    // Update: set arr[1] = 10 and update corresponding segment
    // tree nodes
    updateValue(arr, st, n, 1, 10);
 
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",getSum(st, n, 1, 3));
                                                  
 
    return 0;
}


int getMin(int *st,int arrSize,int left, int right)
{	
	if(left<0 || right>arrSize-1 || left>right)
		return -1;
	getMinUtil(st, left, right, 0,arrSize-1,0);
}

int getMinUtil(int *st, int left, int right, int stLeft, int stRight, int stIndex)
{
	if(stLeft>= left && stRight<=right)
		return st[stIndex];
	
	if((stLeft> right) || (stRight<left))
		return 0;
	
	int mid = (stLeft+stRight)/2;
	
	return (getSumUtil(st, left, right, stLeft, mid, 2*stIndex + 1) + getSumUtil(st, left, right, mid+1, stRight, 2*stIndex + 2));
						
}



int *constructST(int *arr, int n)
{
	int ht = (int)ceil(log2(n));
	int maxSize = 2*(int)pow(2,ht) - 1;
	int *st = new int[maxSize];
	
	segTree(arr, st, 0, n-1, 0);
	return st;
	/*for(int k=0;k<maxSize;k++)
		cout<<st[k]<<"\t";
	cout<<endl;*/
	
}


int segTree(int *arr, int *st, int left, int right,int index)
{
	
	if(left==right)
	{
		st[index]=arr[left];
		return st[index];
	}
	
	int mid = (left+right)/2;
	int leftSum = segTree(arr, st,left, mid, 2*index + 1);
	int rightSum = segTree(arr, st, mid+1, right, 2*index + 2);
	st[index] = leftSum + rightSum;
	return st[index];
}



























