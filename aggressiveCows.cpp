//Using backtracking algorithm here....gives TLE 

#include<iostream>
using namespace std;
void merge_sort(unsigned long long *a,int start,int end);
void merge(unsigned long long *a,int start,int mid,int end);
bool minDist(unsigned long long *stall, int totStalls, unsigned long long curIndex, unsigned long long *minTillNow, unsigned long long lastIndex , int cows);
int main()
{
	int t,totStalls, agCows;
	cin>>t;
	unsigned long long pos,result;
	for(int i=0;i<t;i++)
	{
		cin>>totStalls>>agCows;
		unsigned long long *stall= new unsigned long long[totStalls];
		for(int k=0;k<totStalls;k++)
		{
			cin>>stall[k];
			
		}
		
		merge_sort(stall, 0, totStalls-1);
		
		//send cows = cows-1, mindist = stall[0]-stall[maxlen];	curIndex =1,curd=0
		result = stall[totStalls-1]-stall[0];
		minDist(stall, totStalls, 1,&result,0,agCows-1);
		cout<<result<<endl;
		delete stall;	
	}
	return 0;
}

bool minDist(unsigned long long *stall, int totStalls, unsigned long long curIndex, unsigned long long *minTillNow, unsigned long long lastIndex , int cows)
{
	if(cows > (totStalls - curIndex))
		return false;
	if(cows == 0)
		return true;
	
	unsigned long long tmp1 = *minTillNow,tmp2;
	
	if(*minTillNow > (stall[curIndex]-stall[lastIndex]))
		*minTillNow = stall[curIndex]-stall[lastIndex];
	
	
	//choosing this stall
	if(minDist(stall, totStalls, curIndex+1,minTillNow,curIndex,cows-1 ))
	{
		//checking if not choosing this stall will further reduce the minTillNow
		tmp2=*minTillNow;
		*minTillNow = tmp1;
		if(minDist(stall, totStalls, curIndex+1,minTillNow,lastIndex,cows))
		{
			if(*minTillNow < tmp2)
				*minTillNow = tmp2;
		}
		else
		{
			*minTillNow = tmp2;	
		}
		return true;
	}
	else
	{
		*minTillNow  = tmp1;
		return false;
	}

}

void merge_sort(unsigned long long *a,int start,int end)
{
     if(start>=end)
      return ;
    
    int mid= (start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}

void merge(unsigned long long *a,int start,int mid,int end)
{
	int s=start,m=mid+1,e=end;
	unsigned long long *tmp=new unsigned long long[end-start+1];
	int k=0;
	while(s<=mid && m<=end)
	{
		if(a[s]>a[m])
		 {
		 	tmp[k++]=a[m++];
		 }
		 else
		 {
		 	tmp[k++]=a[s++];
		 }
	}
	while(s<=mid)
	 tmp[k++]=a[s++];
	while(m<=end)
	  tmp[k++]=a[m++];
	
	for(int i=0;i<k;i++)
	{
		a[i+start]=tmp[i];
	}
}


