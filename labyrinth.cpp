//got tle 2 times because i used adjacency matrix..switched to adjacency list !

#include<iostream>
using namespace std;
void bfs(bool **mat, int r,int c, bool **covered, int startx, int starty, int *maxd, int *lastx, int *lasty);
void enqueue(int x, int y,int d, struct node **head);
void maxlen(bool **mat, int r, int c);
void adjList(struct node **treeNode, int e);
//stack
struct node{
	int valuex;
	int valuey;
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
	int t,c,r;
	scanf("%d",&t);
	int freeCount;
	for(int k=0;k<t;k++)
	{
		scanf("%d%d",&c,&r);
		bool **mat = new bool*[r];
		for(int i=0;i<r;i++)
			mat[i]=new bool[c];
		
		char *row = new char[c+1];
		freeCount=0;
		for(int i=0;i<r;i++)
		{
			scanf("%s",row);
			
			for(int j=0;j<c;j++)
			{
				mat[i][j]=false;
				if(row[j] == '.')
				{
					mat[i][j]=true;
					freeCount++;
					
				}
				
			}
		}
		
		
		
		if(freeCount<=1)
			printf("Maximum rope length is 0.\n");
		else if(freeCount==2)
			printf("Maximum rope length is 1.\n");
		else	
			maxlen(mat, r,c);
		for(int i=0;i<r;i++)
			delete mat[i];
		delete mat;	
	}

	return 0;
		
}


void maxlen(bool **mat, int r, int c)
{
	int startx,starty,maxd,lastx,lasty;
	bool **covered=new bool*[r];
	for(int i=0;i<r;i++)
		covered[i]=new bool[c];
	
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
		covered[i][j]=false;
	
	bool found = false;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(mat[i][j])
			{
				startx = i;
				starty = j;
				found=true;
				break;
			}
		}
		if(found)
			break;
	}
	//cout<<startx<<"\t"<<starty<<endl;
	bfs(mat,r,c,covered,startx,starty,&maxd,&lastx,&lasty);
	//cout<<maxd<<endl;
	//cout<<lastx<<"\t"<<lasty<<endl;
	//run the second bfs from the new start point
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
		covered[i][j]=false;
		
	startx = lastx;
	starty= lasty;
	//cout<<startx<<"\t"<<starty<<"\t"<<endl;
	bfs(mat,r,c,covered,startx,starty,&maxd,&lastx,&lasty);
	
	printf("Maximum rope length is %d.\n",maxd);
	delete covered;
}

void bfs(bool **mat, int r,int c, bool **covered, int startx, int starty, int *maxd, int *lastx, int *lasty)
{
	//cout<<"lol1"<<endl;
	struct node *head=new node;
	struct node *tmp;
	head->valuex= startx;
	head->valuey=starty;
	head->next=NULL;
	head->dist=0;
	//cout<<startx<<starty<<endl;
	covered[startx][starty]=true;
	//cout<<"yo"<<endl;
	int curx,cury,curDist;
	while(head!=NULL)
	{
		curx = head->valuex;
		cury = head->valuey;
		curDist = head->dist;
		//cout<<curx<<"\t"<<cury<<"\t"<<curDist<<endl;
		tmp=head;
		//cout<<"lol"<<endl;
		if(curx!=(r-1) && mat[curx+1][cury] && !covered[curx+1][cury])
		{
			covered[curx+1][cury]=true;
			enqueue(curx+1,cury,curDist+1, &head);
		}
		if(curx!=0 && mat[curx-1][cury] && !covered[curx-1][cury])
		{
			covered[curx-1][cury]=true;
			enqueue(curx-1,cury,curDist+1, &head);
		}
		if(cury!=(c-1) && mat[curx][cury+1] && !covered[curx][cury+1])
		{
			covered[curx][cury+1]=true;
			enqueue(curx,cury+1,curDist+1, &head);
		}
		if(cury!=0 && mat[curx][cury-1] && !covered[curx][cury-1])
		{
			covered[curx][cury-1]=true;
			enqueue(curx,cury-1,curDist+1, &head);
		}
		head=head->next;
		delete(tmp);
		//cout<<"hi2"<<endl;
	}
	//cout<<curx<<"\t"<<cury<<"\t"<<curDist<<endl;
	*lastx = curx;
	*lasty = cury;
	*maxd = curDist;
}

void enqueue(int x,int y, int d,struct node **head)
{
	struct node *newNode = new node;
	newNode->valuex = x;
	newNode->valuey = y;
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










