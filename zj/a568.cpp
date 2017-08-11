#include<cstdio>
using namespace std;
int m;
int mul(int a,int b) {return (a *= b) < m ? a : a % m;}
int qpow(int a,int x)
{
	int r = 1;
	for (;x;x>>=1,a=mul(a,a))
		if (x&1)
			r = mul(r,a);
	return r;
}
int main()
{
	int n;
	while (scanf("%d%d",&n,&m) == 2)
		printf("%d\n",
			n == 1 ? 14 % m :
			n == 2 ? 155 % m :
			         mul(1575,qpow(10,n-3))
		);
}
