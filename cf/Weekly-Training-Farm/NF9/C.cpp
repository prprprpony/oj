#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.12e6;
const int M = 999983;
int n;
vector<int> g[maxn];
int d[maxn][3];
void exgcd(int a, ll& x, int b, ll& y, ll& g)
{
	if (b) {
		exgcd(b, y, a % b, x, g);
		y -= a / b * x;
	} else {
		x = 1;
		y = 0;
		g = a;
	}
}
int inv(int a)
{
	ll x, y, g;
	exgcd(M, x, a, y, g);
	assert(g == 1);
	return (y % M + M) % M;
}
inline int add(int a, int b) {return (a += b) < M ? a : a - M;}
inline int mul(int a, int b) {return a * 1LL * b % M;} 
inline int _div(int a, int b) {return mul(a, inv(b));}
void dp(int p, int u)
{
	for (auto v : g[u]) if (v != p)
		dp(u, v);
	d[u][0] = 1;
	for (auto v : g[u]) if (v != p)
		d[u][0] = mul(d[u][0], add(d[v][0], d[v][1]));
	d[u][2] = 1;
	for (auto v : g[u]) if (v != p)
		d[u][2] = mul(d[u][2], d[v][0]);
	if (d[u][1] = d[u][2]) {
		for (auto v : g[u]) if (v != p)
			d[u][1] = add(d[u][1], mul(_div(d[u][2], d[v][0]), d[v][2]));
	} else {
		int cnt0 = 0;
		int v0;
		for (auto v : g[u]) if (v != p && !d[v][0]) {
			v0 = v;
			if (++cnt0 > 1)
				break;
		}
		if (cnt0 == 1) {
			int k = 1;
			for (auto v : g[u]) if (v != p && v != v0)
				k = mul(k, d[v][0]);
			d[u][1] = mul(k, d[v0][2]);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dp(-1,0);
	printf("%d\n", add(d[0][0], d[0][1]));
}
