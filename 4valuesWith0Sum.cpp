#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,sum,index=0;
	cin>>n;
	int a[n],b[n],c[n],d[n];
	int nsq= n*n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	int *aux1=new int[nsq];
	int *aux2=new int[nsq];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		sum = a[i]+b[j];
		aux1[index]=sum;
		
		sum = c[i]+d[j];
		aux2[index] = sum;
		index++;
		
	}
	
	/*merge_sort(aux1, 0, nsq-1);
	merge_sort(aux2, 0, nsq-1);*/
	
	sort(aux1, aux1+nsq);
	sort(aux2, aux2+nsq);
	
	
	/*for(int i=0;i<nsq;i++)
		cout<<aux1[i]<<"\t";
	cout<<endl;
	
	for(int i=0;i<nsq;i++)
		cout<<aux2[i]<<"\t";
	cout<<endl;*/
	
	int result=0;
	
	int a1=0, a2 = nsq-1,tmp,lCount,rCount;
	while(a1<nsq && a2>=0)
	{
		sum = aux1[a1] + aux2[a2];
		if(sum == 0)
		{
			lCount=1, rCount=1;
			tmp=a1+1;
			while(tmp<nsq && aux1[a1]==aux1[tmp])
			{
				lCount++;
				tmp++;
			}
			tmp=a2-1;
			while(tmp>=0 && aux2[a2]==aux2[tmp])
			{
				rCount++;
				tmp--;
			}
			result += (lCount*rCount);
			a1 += lCount;
			a2 -= rCount;
			
		}
		else if(sum<0)
		{
			a1++;
		}
		else
		{
			a2--;
		}
	}	
	cout<<result<<endl;
}

