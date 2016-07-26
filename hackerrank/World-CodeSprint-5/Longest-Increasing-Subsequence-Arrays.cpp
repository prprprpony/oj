#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int maxn = 5.4e5;
int INV[maxn];
int n_1p[maxn];
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
int C(int n, int k)
{
	if (k > n)
		return 0;
	k = min(k, n - k);
	int ret = 1;
	for (int i = 1; i <= k; ++i)
		ret = _div(mul(ret, n - k + i), i);
	return ret;
}
int main()
{
	int p;
	scanf("%d", &p);
	for (int i = 1; i <= 5e5; ++i)
		INV[i] = inv(i);
	while (p--) {
		int m, n;
		scanf("%d%d", &m, &n);
		int ans = 0;
		n_1p[0] = 1;
		for (int i = 1; i <= m - n; ++i)
			n_1p[i] = mul(n_1p[i - 1], n - 1);
		int k = C(m - 1, n - 1);
		int np = 1;
		for (int i = 0; i <= m - n; ++i) {
			ans = add(ans, mul(mul(k, n_1p[m - i - n]), np));
			k = _div(mul(k, m - i - n), m - i - 1);
			np = mul(np, n);
		}
		printf("%d\n", ans);
	}
/*
C(n, k) = n! / k! / (n-k)!
C(n + 1, k) = (n + 1)! / k! / (n + 1 - k)! = C(n, k) * (n + 1) / (n + 1 - k)
*/
}
