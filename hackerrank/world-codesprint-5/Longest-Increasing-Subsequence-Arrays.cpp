#include <cstdio>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int maxn = 5e5;
int INV[maxn + 1];
void exgcd(int a, int b, ll & x, ll & y, ll & g)
{
	if (b) {
		exgcd(b, a % b, y, x, g);
		y -= a / b * x;
	} else {
		g = a;
		x = 1;
		y = 0;
	}
}
int inv(int a)
{
	ll x, y, g;
	exgcd(a, M, x, y, g);
	return ((x % M) + M) % M;
}
inline int add(int a, int b) {return (a += b) < M ? a : a - M;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a : a + M;}
inline int mul(int a, int b) {return a * 1LL * b % M;}
inline int _div(int a, int b) {return mul(a, INV[b]);}
int qpow(int a, int p)
{
	int ret = 1;
	for ( ; p; p >>= 1, a = mul(a, a))
		if (p & 1)
			ret = mul(ret, a);
	return ret;
}
int main()
{
	int p;
	scanf("%d", &p);
	for (int i = 1; i <= maxn; ++i)
		INV[i] = inv(i);
	while (p--) {
		int m, n;
		scanf("%d%d", &m, &n);
		int ans = 0;
		int k = 1;
		int n_1p = 1;
		int np = qpow(n, m - n);
		for (int i = n; i <= m; ++i) {
			//k = C(i - 1, n - 1)
			ans = add(ans, mul(mul(k, n_1p), np));
			k = _div(mul(k, i), i - (n - 1));
			n_1p = mul(n_1p, n - 1);
			np = _div(np, n);
		}
		printf("%d\n", ans);
	}
/*
C(n, k) = n! / k! / (n-k)!
C(n + 1, k) = (n + 1)! / k! / (n + 1 - k)! = C(n, k) * (n + 1) / (n + 1 - k)
*/
}
