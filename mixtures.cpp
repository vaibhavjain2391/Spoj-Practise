#include<iostream>
using namespace std;
void minSmoke(int n, int *color);
int main()
{
	int n,color[100];
	while(cin>>n)
	{
		for(int k=0;k<n;k++)
			cin>>color[k];
		minSmoke(n, color);
	}
	return 0;
}

void minSmoke(int n, int *color)
{
	unsigned long long dpSmoke[n][n],tmp;
	int dpColor[n][n];
	
	for(int i=0;i<n;i++)
	{
		dpSmoke[i][i] = 0;
		dpColor[i][i]=color[i];
	}
	
	for(int d=1;d<n;d++)
	for(int k=0;k<(n-d);k++)
	{
		dpSmoke[k][k+d] = dpSmoke[k][k] + (dpColor[k][k]*dpColor[k+1][k+d]) + dpSmoke[k+1][k+d];
		dpColor[k][k+d]= (dpColor[k][k]+dpColor[k+1][k+d])%100;
		//cout<<dpSmoke[k][k+d]<<endl;
		for(int x=k+1;x<(k+d);x++)
		{
			
			tmp = dpSmoke[k][x] + (dpColor[k][x]*dpColor[x+1][k+d]) + dpSmoke[x+1][k+d];
			//cout<<tmp<<endl;
			if(tmp < dpSmoke[k][k+d])
			{
				dpSmoke[k][k+d]=tmp;
				dpColor[k][k+d]= (dpColor[k][x]+dpColor[x+1][k+d])%100;
			}
			
		}
	}
	
	/*for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
			cout<<dpSmoke[k][i]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
			cout<<dpColor[k][i]<<"\t"<<"\t";
		cout<<endl;
	}*/
	
	cout<<dpSmoke[0][n-1]<<endl;
}




/*

Sample Test Cases
3                                                                 
97 41 41                                                          
5                                                                 
13 37 87 25 17                                                    
12
74 16 14 59 16 92 34 69 4 72 61 20
7
60 44 33 67 9 90 34
5
2 93 72 33 94
10
18 56 59 34 50 93 71 66 98 24
7
94 46 19 44 87 74 45
14
62 77 80 88 77 15 94 51 38 27 66 13 17 94
17
63 57 52 78 55 58 98 68 88 44 63 40 7 99 38 94 87
6
29 34 63 51 96 2
4
57 59 85 37
9
39 54 54 70 87 10 69 62 32
4
26 9 17 37
6
21 11 67 46 43 1
15
8 69 60 0 35 27 96 91 32 51 14 77 58 4 9
11
9 14 94 38 68 40 76 21 24 46 10
2
13 48
10
89 13 53 67 73 75 86 83 71 42
20
27 72 14 71 47 81 45 96 24 8 5 78 49 55 18 69 1 91 55 68
3
88 1 29
18
35 35 68 98 2 48 20 43 8 64 11 38 33 60 28 93 31 22
2
36 31



5535
4310
13997
6159
3037
17569
9581
20035
21575
6319
4760
14189
2753
5752
19037
10205
624
17936
23862
2669
19721
1116



*/




