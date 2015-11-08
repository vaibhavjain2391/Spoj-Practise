#include<iostream>
using namespace std;
bool addNode(struct node **head, int i);
bool deleteNode(struct node **head);
struct node{
	int value;
	struct node *next;
};
bool isBipartite(int **matrix, int bugs);
bool dfs(int root,int **matrix,int bugs,int *color);
int main()
{
	int **matrix= new int*[2000];
	for(int k=0;k<2000;k++)
		matrix[k] = new int[2000];
	int tot,x,y,bugs,links;
	scanf("%d",&tot);
	for(int k=0;k<tot;k++)
	{
		scanf("%d%d",&bugs,&links);
		for(int i=0;i<bugs;i++)
			for(int j=0;j<bugs;j++)
			matrix[i][j]=0;
		
		for(int i=0;i<links;i++)
		{
			scanf("%d%d",&x,&y);
			matrix[x-1][y-1]=1;
			matrix[y-1][x-1]=1;
		}

		if(isBipartite(matrix, bugs))
		{
			printf("Scenario #%d:\n",k+1);
			printf("No suspicious bugs found!\n");
		}
		else
		{
			printf("Scenario #%d:\n",k+1);
			printf("Suspicious bugs found!\n");
		}
	}
	return 0;
}

bool isBipartite(int **matrix, int bugs)
{
	//0: no color, 1: red, 2:blue
	int *color = new int[bugs];
	for(int k=0;k<bugs;k++)
		color[k]=0; 
	
	//int newBugsFound =0;
	//optimization possible for this while loop
	
	for(int i=0;i<bugs;i++)
		{
			if(color[i]==0)
			{
				//newBugsFound++;
				color[i]=1;
				if(!dfs(i,matrix,bugs,color))
				{
					return false;
				}
			}
		}
	//cout<<color[2]<<"\t"<<color[0]<<endl;
	return true;
}


bool dfs(int root,int **matrix,int bugs,int *color)
{
	struct node *head=NULL;
	int parentColor,curNode;
	addNode(&head,root);
	while(head!=NULL)
	{
		curNode = head->value;
		parentColor= color[curNode];
		deleteNode(&head);
		for(int k=0;k<bugs;k++)
		{
			if(matrix[curNode][k]==1) 
			{
				if(color[k]==0)
				{
					addNode(&head,k);
					matrix[k][curNode]=0;
					matrix[curNode][k]=0;
					if(parentColor==1)
						color[k]=2;
					else
						color[k]=1;
				}
				else if(parentColor==color[k])
					return false;
			}
				
		}
	}
	return true;
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

bool deleteNode(struct node **head)
{
	if(*head == NULL)
		return false;
	
	struct node *tmp =*head;
	*head = (*head)->next;
	delete(tmp);
	return true;
}

















