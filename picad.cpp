//maxTime was working..couldn't find algo of minTime
//picad2.cpp contains a much simpler way to solve the same problem

#include<iostream>
#include<limits.h>
using namespace std;
struct node{
	unsigned long long start;
	unsigned long long end;
	struct node *next;
};


unsigned long long maxCount(struct node *head);
unsigned long long staleIntervals(struct node **ehead, unsigned long long end,unsigned long long start);
void addNodeSorted(struct node **head, unsigned long long s, unsigned long long e);
int main()
{
	unsigned long long p,k,a,b,max,min,n;
	struct node *head= NULL;
	for(int test=0;test<10;test++)
	{
		cin>>p>>k;
		cin>>n;
		for(int person=0;person<n;person++)
		{
			cin>>a>>b;
			if(!(a>k || b<p))
				addNodeSorted(&head,a,b);
		}
		if(head==NULL)
			cout<<0<<" "<<0<<endl;
		else
		{
			max = maxCount(head);
			// min =  
		
			//cout<<min<<" "<<max<<endl;
			cout<<max<<endl;
			struct node *tmp= head;
			while(tmp!=NULL)
			{
				head=tmp->next;
				delete(tmp);
				tmp=head;
				
			}
		}
		
	}
	return 0;
}

void maxminCount(struct node *head)
{
	unsigned long long result=0,ecur,curMax=0,maxTillNow=1,count,curMin, minTillNow=ULLONG_MAX;
	struct node *ehead = NULL;	
	struct node *tmp = head;
	bool intervalSpace = false;
	count=staleIntervals(&ehead,tmp->end,tmp->start,&intervalSpace);
	tmp=tmp->next;
	curMax=1;
	while(tmp!=NULL)
	{
		curMax++;
		count = staleIntervals(&ehead,tmp->end,tmp->start,&intervalSpace);
		curMax = curMax - count;
		
		if(curMax > maxTillNow)
			maxTillNow=curMax;
		
		if(intervalSpace)
			minTillNow = 0;
		
		else if(count!=0)
		{
			if(curMax<minTillNow)
				minTillNow = curMax;
		}
		tmp=tmp->next;
	}
	
	//delete ehead
	return maxTillNow;
}

unsigned long long staleIntervals(struct node **ehead, unsigned long long end,unsigned long long start)
{
	struct node *newNode = new node;
	newNode->end = end;
	newNode->start= start;
	unsigned long long count=0;
	if(*ehead == NULL)
	{
		*ehead=newNode;
		newNode->next=NULL;
	}
	else
	{
		struct node *prev=NULL;
		struct node *tmp=(*ehead);
		struct node *ntmp=NULL;
		while(tmp!=NULL && (tmp->end) <end)
		{
			ntmp=tmp->next;
			
			if((tmp->end)<start)
			{
				count++;
				delete(tmp);
				if(prev==NULL)
					*ehead=ntmp;
				else
					prev->next=ntmp;
			}
			else
			{
				prev=tmp;
			}
			tmp=ntmp;
		}
		if(prev==NULL)
			*ehead=newNode;
		else
			prev->next=newNode;
			
		if(tmp!=NULL)
			newNode->next=ntmp;
		else
			newNode->next=NULL;
	}
	return count;
}


void addNodeSorted(struct node **head, unsigned long long s, unsigned long long e)
{
	struct node *newNode = new node;
	newNode->start = s;
	newNode->end = e;
	if(*head == NULL)
	{
		*head=newNode;
		newNode->next=NULL;
	}
	else
	{
		if((*head)->start > s)
		{
			newNode->next=*head;
			*head = newNode;
		}
		else
		{
			struct node *tmp = *head;
			while(tmp->next!= NULL && tmp->next->start < s)
				tmp = tmp->next;
			
			if(tmp->next==NULL)
			{
				tmp->next = newNode;
				newNode->next = NULL;
			}
			else
			{
				newNode->next = tmp->next;
				tmp->next = newNode;	
			}
		}
	}
	
}


















