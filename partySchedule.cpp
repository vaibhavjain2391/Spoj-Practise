#include<iostream>
using namespace std;
void maxFunInBudget(int budget, int *fees, int totParties, int *fun, int curFun, int curFees, int lastFees, int lastFun, int *maxFun, int *maxFees);
void dpMaxFunInBudget(int budget, int *fees, int totParties, int *fun);
int main()
{
	int totBudget,totParties, maxFun, maxFees;
	cin>>totBudget>>totParties;
	int fees[100],fun[100];
	while(totBudget!=0 && totParties!=0)
	{
		if(totBudget==0 || totParties ==0)
			cout<<0<<" "<<0<<endl;
		for(int k=0;k<totParties;k++){
			cin>>fees[k];
			cin>>fun[k];
		}
		/*maxFun=0, maxFees=0;
		maxFunInBudget(totBudget,fees, totParties-1,fun, 0, 0, 0, 0, &maxFun, &maxFees); 
		cout<<maxFees<<" "<<maxFun<<endl;*/
		dpMaxFunInBudget(totBudget, fees, totParties, fun);
		
		cin>>totBudget>>totParties;
	}
}

void dpMaxFunInBudget(int budget, int *fees, int totParties, int *fun)
{
	int funStore[budget+1][totParties+1];
	for(int i=0;i<=totParties;i++)
		funStore[0][i]=0;
	
	for(int i=1;i<=budget;i++)
		funStore[i][0]=0;
	
	int tmp;
	for(int i=1;i<=budget;i++)
	for(int j=1;j<=totParties;j++)
	{
		funStore[i][j]= funStore[i][j-1];
		if(fees[j-1] <= i)
		{	
			tmp = fun[j-1] + funStore[i-fees[j-1]][j-1];
			if(tmp > funStore[i][j])
				funStore[i][j] = tmp;
		}		
	}
	
	tmp = funStore[budget][totParties];
	int k= budget-1;
	while(k>=0 && tmp==funStore[k][totParties])
		k--;
	
	if(k<0)
		cout<<0<<" "<<0<<endl;
	else
		cout<<k+1<<" "<<tmp<<endl;
	
}


//Motivation to use Dynamic Programming !
void maxFunInBudget(int budget, int *fees, int totParties, int *fun, int curFun, int curFees, int lastFees, int lastFun, int *maxFun, int *maxFees)
{
	if(totParties < 0)
	{
		if(curFees > budget)
		{
			curFees -= lastFees;
			curFun -= lastFun; 
		}
		if(*maxFun < curFun)
		{
			*maxFun = curFun;
			*maxFees = curFees;
		}		
		return;
	}
		
	if(curFees < budget)
		maxFunInBudget(budget, fees, totParties - 1, fun, curFun + fun[totParties], curFees + fees[totParties], fees[totParties], fun[totParties], maxFun, maxFees);
		
	maxFunInBudget(budget, fees, totParties - 1, fun, curFun, curFees, lastFees, lastFun, maxFun, maxFees);
	
}

