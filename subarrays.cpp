#include<iostream>
using namespace std;
void addNode(struct node **head, int value, int index);
int giveMax(int lowerIndex, struct node **head);
struct node{
	int value;
	int index;
	struct node *next;
	struct node *prev;
};
int main()
{
	int n,lowerIndex,k,result;
	cin>>n;
	int *array= new int[n];
	struct node *head=NULL;
	struct node *topPtr = NULL;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	cin>>k;
	
	for(int i=0;i<(k-1);i++)
	{
		addNode(&head, array[i],i);
		//cout<<"hi"<<"\t";
	}
	
	
	for(int i=(k-1);i<n;i++)
	{
		//cout<<"hi"<<"\t";
		addNode(&head, array[i],i);
		
		lowerIndex = i-k+1;
		
		result = giveMax(lowerIndex, &head);
		cout<<result<<" ";
	}
	cout<<endl;
	
	
	
}

int giveMax(int lowerIndex, struct node **head)
{
	
	if(((*head)->index) <lowerIndex)
	{
		struct node *tmp = *head,*tmpNext;
		while(tmp!=NULL && tmp->index < lowerIndex)
		{
			tmpNext = tmp->next;
			delete(tmp);
			tmp=tmpNext;
		}
		if(tmp!=NULL)
		{
			tmp->prev = NULL;
			*head=tmp;
			return tmp->value;
		}
	
	}
	else
	{
		return (*head)->value;
	}
}

void addNode(struct node **head, int value, int index)
{	
	if((*head) == NULL)
	{
		//cout<<"1"<<endl;
		struct node *newNode = new node;
		newNode->value = value;
		newNode->index= index;
		newNode->prev= NULL;
		(*head) = newNode;
		newNode->next =NULL;
	}
	
	else if((*head)->value < value)
	{
		//cout<<"2"<<endl;
		struct node *tmp = (*head)->next,*tmpNext;
		(*head)->value = value;
		(*head)->index = index;
		(*head)->next=NULL;
		while(tmp!=NULL)
		{
			tmpNext = tmp->next;
			delete(tmp);
			tmp = tmpNext;
		}
	}
	else
	{
		struct node *tmp = *head,*tmpNext;
		//cout<<"3"<<endl;
		while(tmp->next!=NULL && (tmp->value > value))
		{
			tmp = tmp->next;
		}
		
		if(tmp->value <= value)
		{
			//cout<<"4"<<endl;
			tmpNext=tmp->next;		
			tmp->value = value;
			tmp->index = index;	
			tmp->next=NULL;
			tmp= tmpNext;
			while(tmp!=NULL)
			{
				tmpNext = tmp->next;
				delete(tmp);
				tmp = tmpNext;
			}
		}
		else if(tmp->next==NULL)
		{	
			//cout<<"5"<<endl;
			struct node *newNode = new node;
			newNode->value = value;
			newNode->index= index;
			tmp->next=newNode;
			newNode->prev= tmp;
			newNode->next=NULL;
		}
		
	}

}








