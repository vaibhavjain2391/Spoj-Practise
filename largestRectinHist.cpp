#include<iostream>
using namespace std;
bool addNode(struct node **head, unsigned long long  ht, unsigned long long  index,unsigned long long *maxArea);
bool deleteNode(struct node **head,unsigned long long lastIndex,unsigned long long *maxArea);
struct node{
	unsigned long long  height;
	unsigned long long  position;
	struct node *next;
};
int main()
{
	unsigned long long n,h;
	cin>>n;
	struct node *head=NULL;
	unsigned long long area;
	
	while(n!=0)
	{
		area=0;
		for(unsigned long long  i=0;i<n;i++)
		{
			cin>>h;
			addNode(&head, h, i, &area);
		}
		deleteNode(&head, n, &area);
		cout<<area<<endl;
		cin>>n;
	}
	return 0;
}

bool addNode(struct node **head, unsigned long long ht, unsigned long long index,unsigned long long *maxArea)
{
	struct node *tmp = *head;
	unsigned long long curArea,updatedIndex=-1;
	while(tmp!=NULL && tmp->height>ht)
	{		
		updatedIndex=tmp->position;
		curArea =  (index - (tmp->position))*(tmp->height);
		if(curArea > *maxArea)
			*maxArea = curArea;
		
		*head=(*head)->next;
		delete(tmp);
		tmp=*head;		
	}
	
	if(tmp!=NULL && tmp->height==ht)
		return true;
		
	struct node *newNode = new node;
	newNode->height = ht;	
	if(updatedIndex!=-1)
		newNode->position = updatedIndex;
	else
		newNode->position = index;
		
	if(*head == NULL)
	{
		*head=newNode;
		newNode->next=NULL;
	}
	else
	{
		newNode->next= *head;
		*head = newNode;
	}
	return true;
}

bool deleteNode(struct node **head,unsigned long long lastIndex,unsigned long long *maxArea)
{
	struct node *tmp;
	while(*head!=NULL)
	{
		unsigned long long curArea;
		tmp =*head;
		curArea =  (lastIndex - (tmp->position))*(tmp->height);
		//cout<<curArea<<endl;
		if(curArea > *maxArea)
			*maxArea = curArea;
			
		*head = (*head)->next;
		delete(tmp);
	}
		return true;
}



