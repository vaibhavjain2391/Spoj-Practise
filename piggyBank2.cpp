#include<iostream>
using namespace std;
void minCash(int targetWt,int coinsType,struct coin *head);
void addCoin(int value, int wt, struct coin **head);
struct coin
{
	int value;
	int weight;
	double valPerGm;
	struct coin *next;
};
int main()
{
	int t;
	cin>>t;
	int empty,filled,targetWt,coinsType,value,wt;
	for(int i=0;i<t;i++)
	{
		cin>>empty>>filled;
		targetWt = filled - empty;	
		cin>>coinsType;
	
		struct coin *head=NULL;
		for(int k=0;k<coinsType;k++)
		{
			cin>>value;
			cin>>wt;
			addCoin(value, wt, &head);
		}
		if(targetWt==0)
			cout<<"The minimum amount of money in the piggy-bank is 0."<<endl;
		else
			minCash(targetWt, coinsType, head);
	}
}

void minCash(int targetWt,int coinsType,struct coin *head)
{
	int resValue=0, totCoins;
	while(head!=NULL && targetWt>0)
	{
		if(targetWt>= head->weight)
		{
			totCoins = targetWt/(head->weight);
			resValue += ((head->value)*totCoins);
			targetWt -= ((head->weight)*totCoins);
		}
		head=head->next;
	}
	if(head==NULL)
		cout<<"This is impossible."<<endl;
	else
		cout<<"The minimum amount of money in the piggy-bank is "<<resValue<<"."<<endl;
}

void addCoin(int value, int wt, struct coin **head)
{
	double curValPerGm = value/wt;
	struct coin *newNode = new coin;
	newNode->weight = wt;
	newNode->value = value;
	newNode->valPerGm = curValPerGm;
	newNode->next=NULL;
	if(*head==NULL)
	{
		*head = newNode;
	}
	else if((*head)->valPerGm > curValPerGm)
	{
		newNode->next = *head;
		*head=newNode;
	}
	else
	{
		struct coin *tmp = *head;
		while(tmp->next!=NULL && tmp->next->valPerGm < curValPerGm)
			tmp=tmp->next;
		
		if(tmp->next==NULL)
		{
			tmp->next=newNode;
		}
		else
		{
			newNode->next = tmp->next;
			tmp->next=newNode;
		}
	}
}























