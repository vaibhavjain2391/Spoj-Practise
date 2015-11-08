#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str[1100];
	cin.getline(str,sizeof(str));
	char x = str[0];
	bool isTauto;
	int curIndex,diff,len;
	//cout<<str<<endl;
	while(x!='*')
	{
		isTauto = true;
		if(x>='a' && x<='z')
			diff = x-'a';
		else
			diff = x-'A';
		
		len = strlen(str);
		curIndex=1;
		while(curIndex < len)
		{
			//cout<<"j"<<endl;
			if(str[curIndex]==' ')
			{
				curIndex++;
				x = str[curIndex];
				if(!((x-'a')==diff || (x-'A')==diff))
				{
					cout<<"N"<<endl;
					isTauto = false;
					break;
				}
			}
			curIndex++;
			
		}
		if(isTauto)
			cout<<"Y"<<endl;
		cin.getline(str,sizeof(str));
		x= str[0];
	}
	return 0;
}
