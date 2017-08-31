#include<cstdio>
using namespace std;
const int N = 1e6 + 1, NP = 78498;
int lp[N], vp[NP];
int mul(int a,int b,int m) {return a * 1LL * b % m;}
int qpow(int a,int b,int m)
{
	int r = 1;
	for (;b;b>>=1,a=mul(a,a,m))
		if (b&1)
			r = mul(r, a, m);
	return r;
}
void pre()
{
	for (int i = 2, s = 0; i < N; ++i) {
		if (!lp[i]) 
			vp[s++] = lp[i] = i;
		for (int k = 0, j; k < s && (j = vp[k]) <= lp[i] && i * 1LL * j < N; ++k)
			lp[i * j] = j;
	}
}
int main()
{
	pre();
	int n,m;
	while (scanf("%d%d",&n,&m) == 2 && n) {
		int ans = 1;
		for (int p : vp) {
			if (p > n)
				break;
			int x = n, t = 0;
			while (x /= p) t += x;
			ans = mul(ans, qpow(p, t, m), m);
		}
		printf("%d\n", ans);
	}
}
