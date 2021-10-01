#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long double LD;


#include <stdio.h>
//macro precendence

#define square(x) x*x
//the above is wrong because if it is called with
//z+1, the precendence will make it wrong

#define max(x,y) (((x)>(y))?(x):(y))
//if called with max(i++, j++), max will be
//inceremented twice

#define SWAP(t,x,y) {t SWAP = y; y=x; x=SWAP;}

#define forever for(;;)
//macros just replace a line
#define FOR(i,a,b) for (int i = a; i < b; i++)
//popular macros on code forces
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
inline void pt(int a){
	printf("%d",a);
}
int main(){
	pt(10);
	int a=100;
	int b=129;
	SWAP(int,a,b);
	printf("%d %d",a,b);
}