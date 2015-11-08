//Most probable reason for getting SIGSEGV error : taking too much memory

#include<iostream>
using namespace std;
bool addNode(struct node **head, int i,int p);
bool deleteNode(struct node **head);
struct node{
	int value;
	struct node *next;
	int parent;
};

int main()
{
	int nodes,edges,n1, n2;
	cin>>nodes;
	cin>>edges;
	
	bool graph[nodes][nodes],cycleFound=false;
	for(int i=0;i<nodes;i++)
	for(int j=0;j<nodes;j++)
		graph[i][j]=0;
	for(int k=0;k<edges;k++)
	{
		cin>>n1>>n2;
		if(n1==n2)
			cycleFound=true;
		graph[n1-1][n2-1] = true;
		graph[n2-1][n1-1] = true;
	}
	
	
	if(cycleFound || nodes==0 || (edges!=(nodes-1)))
	{
		cout<<"NO"<<endl;
	}
	else if(nodes==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		bool visited[nodes];
		for(int k=0;k<nodes;k++)
			visited[k]=false;
	
		struct node *head=NULL;
		addNode(&head, 0, -1);	
		int totVisited = 0,curNode,curParent;
		while(totVisited < nodes && !cycleFound)
		{
		//tree ==> no loop, connected graph
			if(head==NULL || visited[head->value])
			{
				cout<<"NO"<<endl;
				break;
			}
			curNode = head->value;
			curParent = head->parent;
			deleteNode(&head);
		
			visited[curNode]=true;
			for(int x=0;x<nodes;x++)
			{
				if(graph[curNode][x])
				{
					if(visited[x]  && x!=curParent)
					{
						cout<<"NO"<<endl;
						cycleFound=true;
					//cout<<curParent<<"\n"<<curNode<<"\n"<<x<<endl;
						break;
					}
					else 
					{
						addNode(&head,x,curNode);
						totVisited++;
					}
				}
			}
		}
	
		if(totVisited==nodes && !cycleFound)
			cout<<"YES"<<endl;
		}
	return 0;
}

bool addNode(struct node **head, int i, int p)
{
	struct node *newNode = new node;
	newNode->value = i;	
	newNode->parent=p;
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


bool deleteNode(struct node **head)
{
	if(*head == NULL)
		return false;
	
	struct node *tmp =*head;
	*head = (*head)->next;
	delete(tmp);
	return true;
}


