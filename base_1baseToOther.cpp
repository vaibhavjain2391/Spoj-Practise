#include<iostream>
#include<string.h>
using namespace std;
void convertFromBaseTen(unsigned long long noBaseTen,char *result,int b2);
void convert( char *number,char *result,int len, int b1, int b2);
void convertToBaseTen(unsigned long long *noBaseTen,char* number,int len,int b1);
int main()
{
	int b1, b2, len;
	char number[8];
	cin>>number;
	len = strlen(number);
	cin>>b1>>b2;
	char result[20];
	convert(number,result,len,b1,b2);
	len =strlen(result);
	if(len>7)
		printf("ERROR\n");
	for(int k=0;k<len;k++)
		cout<<result[k];
	cout<<endl;
}

void convert( char *number,char *result,int len,  int b1,int b2)
{
	unsigned long long noBaseTen=0;
	
	//converting to base 10
	
	convertToBaseTen(&noBaseTen, number,len, b1);
	
	cout<<noBaseTen<<endl;
	//converting from base10 number to b2
	
	convertFromBaseTen(noBaseTen,result, b2);

	
}

void convertToBaseTen(unsigned long long *noBaseTen,char* number,int len, int b1)
{
	int index=len-1, factor=1,tmp;
	*noBaseTen=0;

	while(number[index])
	{
		//handle in different way if number[index] is character, A-F
		if(number[index]>='A' && number[index]<='Z')
		{
			tmp = number[index]-'A';
			tmp += 10;
		}
		else
			tmp = number[index]-'0';
			
 		*noBaseTen  += (tmp*factor);
		index--;
		factor = factor*b1;
	}
	
}

//not wokring fine..fix it !!
void convertFromBaseTen(unsigned long long noBaseTen,char *result,int b2)
{
	int factor, dividend, remainder, index=0,tmp,rIndex=0;
	factor = b2;
	char tmpArr[20];
	while(noBaseTen > 0)
	{
		remainder = noBaseTen%factor;
		if(remainder > 9)
		{
			tmp = remainder - 10;
			tmpArr[index]= ('A'+ tmp);
		}
		else
		{
			tmpArr[index] = (remainder + '0');
		}
		
		noBaseTen = noBaseTen/factor;
		index++;
	}
	
	
	for(int k=index-1;k>=0;k--)
	{
		result[rIndex++] = tmpArr[k];
	}
	result[rIndex]='\0';
}





















