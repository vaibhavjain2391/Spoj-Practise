//not completed yet !

#include<iostream>
using namespace std;
void enqueue(int k, struct node **head);
void runbfs(bool **mat, int n);
void bfs(bool **mat, int n, bool *covered, int start);
//queue
struct node{
	int value;
	int mincost;
	struct node *next;
};

int main()
{
	char **mat =new char*[26];
	for(int i=0;i<26;i++)
		mat[i]=new char[26];
	
	int w,h,startw,starth;
	scanf("%d%d",&w,&h);
	char inchr;
	
	while(w!=0 && h!=0)
	{
		for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			scanf("%c",&inchr);
			if(inchr == 'S')
			{
				starth = i;
				startw = j;
			}
			mat[i][j] = inchr;
		}
	
	
		rundfs(mat,h, w, starth, startw);
		scanf("%d%d",&w,&h);
	}
	return 0;
		
}

void runbfs(char **mat, int h, int w, int starth, int startw)
{
	bool **covered=new bool*[h];
	for(int i=0;i<h;i++)
		covered[i]=new bool*[w];
		
		
	for(int i=0;i<h;i++)
	for(int j=0;j<w;j++)
		covered[i][j]=false;
		
	bfs(mat,h,w,covered,starth, startw);
}

void bfs(char **mat, int h, int w, bool **covered, int starth,int startw)
{
	struct node *head=new node;
	struct node *tmp;
	head->valueh= starth;
	head->valuew= startw;
	head->next=NULL;
	
	covered[starth][startw]=true;
	int curNodeh,curNodew;
	while(head!=NULL)
	{
		curNodeh = head->valueh;
		curNodew = head->valuew;
		tmp=head;
		head=head->next;
		delete(tmp);
		
		if((curNodeh+1)< h && mat[curNodeh+1][curNodew]!='X')		
			editCost(mat[curNodeh+1][curNodew],parentCost, cost, curNodeh+1,curNodew);
		
		if((curNodew+1)< w && mat[curNodeh][curNodew+1]!='X')		
			editCost(mat[curNodeh][curNodew+1],parentCost, cost, curNodeh,curNodew+1);
			
		if((curNodeh+1)< h && mat[curNodeh+1][curNodew]!='X')		
			editCost(mat[curNodeh+1][curNodew],parentCost, cost, curNodeh+1,curNodew);
		
		if((curNodeh+1)< h && mat[curNodeh+1][curNodew]!='X')		
			editCost(mat[curNodeh+1][curNodew],parentCost, cost, curNodeh+1,curNodew);
		
		
			if(curChar == 'D')
			{
				if(cost[
			}
			else
			{
				
			}
			if(mat[curNodeh+1][curNodew] == 0)
			
			covered[k]=true;
			enqueue(k, &head);
		}
	}
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








