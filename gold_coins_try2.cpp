#include<iostream>
using namespace std;
unsigned long maxDollar(unsigned long n);
unsigned long history[10000000];
int main()
{
                for(unsigned long i=0;i<10000000;i++)
                                history[i]=-1;
                history[0]=1; //case 1
                history[1]=2;
                unsigned long n,result;
                while(cin>>n)
                {
                                if(n==0)
                                {
                                                cout<<n<<endl;
                                }
                                else
                                {
                                                result = maxDollar(n);
                                                cout<<result<<endl;
                                }
                                
                }
                return 0;
}

unsigned long maxDollar(unsigned long n)
{
		
                if(n<=0)
                                return 0;
                if(n==1)
                                return 1;
                
                if(n==2)
                                return 2;
                
                unsigned long sum=0,tmp;
                
                tmp=n/2;
                if(tmp>0 && tmp<10000000 && history[tmp-1] != -1)
                                sum = history[tmp-1];
                else
                                sum = maxDollar(tmp);
                                
                tmp=n/3;
                if(tmp>0 && tmp<10000000 && history[tmp-1] != -1)
                                sum += history[tmp-1];
                else
                                sum += maxDollar(tmp);
                                
                tmp=n/4;
                if(tmp>0 && tmp<10000000 && history[tmp-1] != -1)
                                sum += history[tmp-1];
                else
                                sum += maxDollar(tmp);
                
                if(sum > n)
                {
                                if(n<10000000)
                                                history[n-1]=sum;
                                return sum;
                }
                else
                {
                                if(n<10000000)
                                                history[n-1]= n;
                                return n;
                }

}

