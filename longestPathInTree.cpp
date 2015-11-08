//got tle 2 times because i used adjacency matrix..switched to adjacency list !

#include<iostream>
using namespace std;
void bfs(struct node **treeNode, int n, bool *covered, int start, int *maxd, int *lastNode);
void enqueue(int k,int d, struct node **head);
void maxlen(struct node **treeNode, int n);
void adjList(struct node **treeNode, int e);
//stack
struct node{
	int value;
	int dist;
	struct node *next;
};


/*
Idea is to run dfs two times : 

1) start from a random node, find the deepest node from this start point
2) Run the dfs from this deepest node, it returns the longest path
*/

 
int main()
{
	int n,u,v;
	scanf("%d",&n);
	
	struct node *treeNode[n];
	for(int k=0;k<n;k++)
		treeNode[k]=NULL;
	
	int e= n-1;
	
	for(int i=0;i<e;i++)
	{
		scanf("%d%d",&u,&v);
		adjList(&(treeNode[u-1]),v-1);
		adjList(&(treeNode[v-1]),u-1);
	}
	
	maxlen(treeNode, n);
	return 0;
		
}

void adjList(struct node **treeNode, int e)
{
	struct node *edge = new node;
	edge->value = e;
	edge->dist = -1; //not applicable
	if(*treeNode==NULL)
	{
		*treeNode = edge;
		edge->next=NULL;
	}
	else
	{
		edge->next=*treeNode;
		*treeNode = edge;
	}
	return ;
}
void maxlen(struct node **treeNode, int n)
{
	int start = 0,maxd; //random point to start from
	bool *covered=new bool[n];
	for(int i=0;i<n;i++)
	{
		covered[i]=false;
	}
		
	int lastnode;
	bfs(treeNode,n,covered,start,&maxd,&lastnode);
	
	//run the second bfs from the new start point
	for(int i=0;i<n;i++)
	{
		covered[i]=false;
	}
	start = lastnode;
	bfs(treeNode,n,covered,start,&maxd,&lastnode);
	
	printf("%d\n",maxd);
	delete covered;
}

void bfs(struct node **treeNode, int n, bool *covered, int start, int *maxd, int *lastNode)
{
	struct node *head=new node;
	struct node *tmp,*treeTmp;
	head->value= start;
	head->next=NULL;
	head->dist=0;
	covered[start]=true;
	int curNode,curDist,curEdge;
	while(head!=NULL)
	{
		curNode = head->value;
		curDist = head->dist;
		tmp=head;
		head=head->next;
		delete(tmp);
		treeTmp = treeNode[curNode];
		while(treeTmp!=NULL)
		{
			curEdge = treeTmp->value;
			if(!covered[curEdge])
			{
				covered[curEdge]=true;
				enqueue(curEdge,curDist+1, &head);
			}
			treeTmp=treeTmp->next;
		}
	}
	*lastNode = curNode;
	*maxd = curDist;
}

void enqueue(int k, int d,struct node **head)
{
	struct node *newNode = new node;
	newNode->value = k;
	newNode->dist = d;
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










