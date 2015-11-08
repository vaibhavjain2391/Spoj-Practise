//using too much space ..wtf !!

#include<iostream>					
int main(){int t,s[5050],n,z,r,c,k,i;scanf("%d",&t);for(i=0;i<t;i++){scanf("%d",&n);z=(n*(n+1))/2;for(k=0;k<z;k++){scanf("%d",&s[k]);}z=z-n-1;r=n-1;c=r;for(k=z;k>=0;k--){s[k]+=((s[k+r]>s[k+r+1])?s[k+r]:s[k+r+1]);if(c==1){r--;c = r;}else c--;}printf("%d\n",s[0]);}}

