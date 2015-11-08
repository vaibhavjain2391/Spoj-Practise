#include<iostream>
using namespace std;

//0 not a friend, 1 my friend, 2 probably my friend of friend
//4 digit : max 10x10x10x10 entries
int main()
{
	int myFriends,result, friendId, totFriends;
	cin>>myFriends;
	int *hash=new int[11000];
	for(int i=0;i<11000;i++)
		hash[i]=0;
	result=0;
	for(int k=0;k<myFriends;k++)
	{
		cin>>friendId;
		if(hash[friendId]==2)
		{
			result -= 1;
		}
		hash[friendId]=1;
		
		cin >> totFriends;
		for(int x=0;x<totFriends;x++)
		{
			cin>>friendId;
			if(hash[friendId] != 1)
			{		
				if(hash[friendId] == 0)
				{
					hash[friendId] = 2;
					result++;
				}
				//if not => friend is already considered once
			}
			
		}
	}
	cout<<result<<endl;
	delete hash;
	return 0;
}
