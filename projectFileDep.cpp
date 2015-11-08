#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void enqueue(int k, struct node **head);
bool addNode(struct node **head, int i);
void printStack(struct node *head);
void printProjGraph(bool **mat, int n);
void runTopoSort(bool **mat, int start, int n, bool *covered);

//https://code.google.com/p/kuba-cs371p-pfd/wiki/PFD_Description

//queue
struct node{
	int value;
	struct node *next;
};

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    printf("/n");
}
 
 
int main()
{
	int n,m,dependent,dependency,tot;
	scanf("%d%d",&n,&m);
	
	bool *independent = new bool[n];
	bool **mat = new bool*[n];
	for(int i=0;i<n;i++)
		mat[i]= new bool[n];
	
	for(int i=0;i<n;i++)
	{
		independent[i]=true;
		for(int j=0;j<n;j++)
			mat[i][j]=false;
	}
	

	for(int i=0;i<m;i++)
	{
		scanf("%d",&dependent);
		scanf("%d",&tot);
		independent[dependent]=false;
		for(int k=0;k<tot;k++)
		{
			scanf("%d",&dependency);
			mat[dependent-1][dependency-1]=true;
		}
	}
	
	priority_queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(independent[i])
			q.push(i);
	}
	delete independent;
	printProjGraph(mat, n,q);
	cout<<endl;
	return 0;	
}


void printProjGraph(bool **mat, int n, priority_queue<int> *q )
{
	bool *covered = new bool[n];
	for(int i=0;i<n;i++)
		covered[i]=false;
		
	for(int i=0;i<n;i++)
	{
		if(!covered[i])
		{
			covered[i]=true;
			runTopoSort(mat, i, n, covered);
		}
	}
}

void runTopoSort(bool **mat, int start, int n, bool *covered)
{
	struct node *head=NULL;
	struct node *tmp;
	struct node *resultStack = NULL;
	enqueue(start, &head);
	int index;

	
	while(head!=NULL)
	{
		index = head->value;
		for(int k=0;k<n;k++)
		{
			if(!covered[k] && mat[index][k])
			{
				covered[k]=true;
				enqueue(k, &head);
			}
		}
		
		tmp= head;
		head=head->next;
		delete tmp;
		addNode(&resultStack, index);
	}
	printStack(resultStack);
}


void enqueue(int k, struct node **head)
{
	struct node *newNode = new node;
	newNode->value = k;
	newNode->next=NULL;
	if((*head) ==  NULL)
	{
		*head = newNode;
	}
	else
	{
		struct node *tmp = *head;
		while(tmp->next!=NULL)
			tmp=tmp->next;
		
		tmp->next=newNode;
	}
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
	if(head != NULL)
	{
		struct node *tmp = NULL;
		tmp = head;
		while(tmp!= NULL)
		{
			printf("%d ",tmp->value+1);
			tmp = tmp->next;
		}
	}
	//cout<<endl;
}















