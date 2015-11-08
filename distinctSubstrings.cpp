//TRIE Solution : memory consuming  !

#include<iostream>
#include<string.h>
using namespace std;
struct node{
	struct node *next[26];
	bool visited;
};
int distictSubstr(struct node* head,char *str,int len);
bool updateTrie(struct node *head, char *str, int st, int en);
void resetTrie(struct node *head);
int main()
{
	int t,len,result;
	cin>>t;
	char str[1002];
	struct node *head=new node;
	head->visited=false;
	for(int i=0;i<26;i++)
		head->next[i]=NULL;
	for(int i=0;i<t;i++)
	{
		cin>>str;
		len = strlen(str);
		result= distictSubstr(head,str,len);
		cout<<result<<endl;
		resetTrie(head);
	}
}

int distictSubstr(struct node* head,char *str,int len)
{
	int result=0;
	for(int i=0;i<len;i++)
	for(int j=i;j<len;j++)
	{
		result += updateTrie(head, str, i, j);
	}
	return result;
}

bool updateTrie(struct node *head, char *str, int st, int en)
{
	struct node *tmp = head;
	char x;
	for(int k=st;k<en;k++)
	{
		x= str[k]-'A';
		if(tmp->next[x]==NULL)
		{
			tmp->next[x]=new node;
			tmp = tmp->next[x];
			tmp->visited = false;		
			for(int i=0;i<26;i++)
			{
				tmp->next[i]=NULL;
			}
		}
		else
			tmp=tmp->next[x];
	}
	
	bool firstVisit = true;
	x= str[en]-'A';
	if(tmp->next[x]==NULL)
	{
		tmp->next[x]=new node;
		tmp = tmp->next[x];
		tmp->visited = false;
		for(int i=0;i<26;i++)
			tmp->next[i]=NULL;
	}
	else
		tmp=tmp->next[x];
			
	if(tmp->visited == true)
		firstVisit = false;
	
	else
		tmp->visited = true;
	
	return firstVisit;
	
	
}



void resetTrie(struct node *head)
{
	if(head==NULL)
		return;
	for(int i=0;i<26;i++)
	{
		if(head->next[i] !=NULL && (head->next[i])->visited == true)
			(head->next[i])->visited = false;
		resetTrie(head->next[i]);
	}
	return;
}
















