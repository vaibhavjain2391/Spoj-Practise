/*

use the formula for volume of irregular tetrahedral of given sides. first pair the given sides such that they don't have any common vertices. and name it (u,U),(v,V), (w,W) Volume = sqrt(4*u*u*v*v*w*w- u*u*sqr((v*v+w*w - U*U)) - v*v*sqr((w*w+u*u - V*V)) - w*w*sqr((u*u + v*v - W*W)) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W))/12;

Also you can think in tartaglia theorem Determinant with: Leibniz and inversions with: fenwick tree.

Reference: http://www.cs.berkeley.edu/~wkahan/VtetLang.pdf

*/

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	int t;
	cin>>t;
	double ab, ac, ad, bc, bd, cd; //some edges may be not integral
	double x1, x2, x3, x4, x5, tmp1, tmp2, tmp3, result, absq, acsq, adsq, bcsq, bdsq, cdsq;
	for(int i=0;i<t;i++)
	{
		cin>>ab>>ac>>ad>>bc>>bd>>cd;
			
		//pairing : (ab,cd)(ac,bd)(ad,bc)
		//(u,U),(v,V), (w,W) 
		
		absq = ab*ab;
		acsq = ac*ac;
		adsq = ad*ad;
		bcsq = bc*bc;
		bdsq = bd*bd;
		cdsq = cd*cd;
		
		//Volume = sqrt(4*u*u*v*v*w*w- u*u*sqr((v*v+w*w - U*U)) - v*v*sqr((w*w+u*u - V*V)) - w*w*sqr((u*u + v*v - W*W)) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W))/12;
		
		x1 = 4*absq*acsq*adsq;
		
		tmp1 = acsq + adsq - cdsq;
		x2 = absq*tmp1*tmp1;
		
		tmp2 = adsq + absq - bdsq;
		x3 = acsq*tmp2*tmp2;
		
		tmp3 = acsq + absq - bcsq;
		x4 = adsq*tmp3*tmp3;
		
		x5 = tmp1*tmp2*tmp3;
		
		result = x1  - x2 - x3 -x4 + x5;
		result = sqrt(result);
		result = result/12;
		cout<<fixed<<setprecision(4)<<result<<endl;
	}
	return 0;
}

















