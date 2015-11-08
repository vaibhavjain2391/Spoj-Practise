#include<iostream>
#include<string.h>
using namespace std;
struct node{
	bool visited;
	bool end;
	struct node *next[10];
};
bool fillTrie(struct node *head,char *str, int len);
void deleteTrie(struct node **head);
int main()
{
	int t,n,len;
	cin>>t;
	bool consistent;
	char str[15];
	struct node *head;

	for(int i=0;i<t;i++)
	{
		head=new node;
		for(int k=0;k<10;k++)
		head->next[k] = NULL;
		
		consistent = true;
		cin>>n;
		for(int k=0;k<n;k++)
		{
			cin>>str;
			len = strlen(str);
			if(consistent)
			{
				if(!fillTrie(head,str,len))
					consistent = false;
			}
			
		}
		if(consistent)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		deleteTrie(&head);
		
	}
	return 0;
}

bool fillTrie(struct node *head,char *str, int len)
{
	/*

		false will be returned in two cases :
		1) node is visited and my string end here
		2) a string visits a node where already a string has ended
		
	*/
	char x;
	struct node *tmp = head,*prev;
	for(int i=0;i<len;i++)
	{
		x=str[i];
		prev = tmp;
		tmp=tmp->next[x-'0'];
		if(tmp==NULL)
		{
			struct node *newNode = new node;
			newNode->visited = true;
			if(i==(len-1))
				newNode->end = true;
			else
				newNode->end = false;
			for(int k=0;k<10;k++)
				newNode->next[k]=NULL;
			prev->next[x-'0'] = newNode;
			tmp=newNode;
		}
		else
		{
			if(tmp->end)
				return false;
			
			if(tmp->visited==false)
				tmp->visited = true;
			else
			{
				if(i==len-1)
					return false;
			}
		}
	}
	return true;
}


void deleteTrie(struct node **head)
{
	struct node *tmp = *head;
	for(int i=0;i<10;i++)
	{
		if(tmp->next[i]!=NULL)
			deleteTrie(&(tmp->next[i]));
			
	}
	delete tmp;
}















