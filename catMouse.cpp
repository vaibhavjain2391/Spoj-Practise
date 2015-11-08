//check if the mouse and cat positions are same(NO), if the mouse is already on border(YES), and if all three are are on diagonal(NO)


#include<iostream>
using namespace std;

int abs(int a)
{
	if(a<0)
		return -a;
	else
		return a;
}
int main()
{
	int n, m, mx, my,c1x, c1y, c2x, c2y,k, diffx1, diffy1, diffx2, diffy2;
	cin>>n>>m;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>mx>>my;
		cin>>c1x>>c1y;
		cin>>c2x>>c2y;
		
		if((mx==c1x && my==c1y)||(mx==c2x && my==c2y))
			printf("NO\n");
		else if(mx==1 || mx==n || my==1 || my==m)
			printf("YES\n");
		
		else if((mx<c1x && mx<c2x) || (mx>c1x && mx>c2x) || (my>c1y && my>c2y) || (my<c1y && my<c2y))
			printf("YES\n");
		else{
			diffx1 =  abs(mx - c1x);
			diffy1 = abs(my - c1y);
			diffx2 = abs(mx - c2x);
			diffy2 = abs(my - c2y);
			if((diffx1 == diffy1) && (diffx2 == diffy2))
				printf("NO\n");
			else
				printf("YES\n");		
		}	
		
	}
	return 0;
}

