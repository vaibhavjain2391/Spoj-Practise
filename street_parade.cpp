#include<iostream>
using namespace std;
bool addNode(struct node **head, int i);
void printStack(struct node *head);
bool deleteNode(struct node **head);
bool possible(int *mainRoad, int trucks);
struct node{
	int value;
	struct node *next;
};

int main()
{
	int road1[1000];
	int trucks;
	cin>>trucks;
	while(trucks != 0)
	{
		for(int i=0;i<trucks;i++)
			cin>>road1[i];
		
		if(possible(road1, trucks))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		cin>>trucks;
	}
}


//use proper stack..arrays are making things difficult
bool possible(int *mainRoad, int trucks)
{
	struct node *sideRoad = NULL;
	int mainRoadIndex= 0,sideTopNode;
	
	int expected = 1;
	for(int k=0;k<trucks;k++)
	{
		if(mainRoad[k]==expected)
			expected++;
		else
		{
			sideTopNode = (sideRoad!=NULL)?(sideRoad->value):0;
			while(sideTopNode == expected)
			{
				expected++;
				deleteNode(&sideRoad);
				sideTopNode = (sideRoad!=NULL)?(sideRoad->value):0;
			}
			if(mainRoad[k]==expected)
				expected++;
			else
				addNode(&sideRoad, mainRoad[k]);
		}
	}
	sideTopNode = (sideRoad!=NULL)?(sideRoad->value):0;
	while(sideTopNode == expected)
	{
		expected++;
		deleteNode(&sideRoad);
		sideTopNode = (sideRoad!=NULL)?(sideRoad->value):0;
	}
	//cout<<expected<<endl;
	if(expected == (trucks+1))
		return true;
	else
		return false;
}

bool addNode(struct node **head, int i)
{
	struct node *newNode = new node;
	newNode->value = i;	
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

void printStack(struct node *head)
{
	if(head == NULL)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		struct node *tmp = NULL;
		tmp = head;
		while(tmp!= NULL)
		{
			cout<<tmp->value<<"  ";
			tmp = tmp->next;
		}
	}
	cout<<endl;
}



bool deleteNode(struct node **head)
{
	if(*head == NULL)
		return false;
	
	struct node *tmp =*head;
	*head = (*head)->next;
	delete(tmp);
	return true;
}


