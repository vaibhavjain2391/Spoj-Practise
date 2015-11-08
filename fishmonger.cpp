#include<iostream>
using namespace std;

void rundfs(bool **mat, int n);
void dfs(bool **mat, int n, bool *covered, int start);
void addToStack(int k, struct node **head);
//stack
struct node{
	int value;
	struct node *next;
};

int main()
{
	int n, t;
	int **mat = new int*[50];
	for(int i=0;i<50;i++)
		mat[i]= new int[1000];
	
	scanf("%d%d",&n,&t);	
	while(n!=0 && t!=0)
	{
		for(int i=0;i<n;i++)
		for(int i=0;j<n;j++)
			scanf("%d",&mat[i][j];
	}
	rundfs(mat,n,t);
}


void rundfs(int **mat, int n, int maxTime)
{
	bool covered[n];
	
	int  minMoney, mtmp, curTime;
		
	covered[0]=true;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
			covered[i]=false;
		co
		count=1;
		dfs(mat, n, covered, i, count, time );
		
	}
}

void dfs(bool **mat, int n, bool *covered, int start)
{
	struct node *head=new node;
	struct node *tmp;
	head->value= start;
	head->next=NULL;
	covered[start]=true;
	int curNode;
	while(head!=NULL)
	{
		curNode = head->value;
		tmp=head;
		head=head->next;
		delete(tmp);
		cout<<curNode+1<<"\t";
		for(int k=0;k<n;k++)
		{
			if(!covered[k] && mat[k][curNode])
			{
				covered[k]=true;
				addToStack(k, &head);
			}
		}
	}
}


void addToStack(int k, struct node **head)
{
	struct node *newNode = new node;
	newNode->value = k;
	if(*head==NULL)
	{
		*head=newNode;
		newNode->next=NULL;
	}
	else
	{
		newNode->next=*head;
		*head=newNode;
	}
}



