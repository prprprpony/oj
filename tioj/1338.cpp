#include "lib1338.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.12e6;
const int maxd = __lg(maxn) + 1;
int n;
ll * A;
template<typename fun>
struct st
{
	fun f;
	ll t[maxd][maxn];
	void init()
	{
		copy(A, A + n, t[0]);
		for (int i = 0; (1 << i) < n; ++i)
			for (int j = 0; j + (1 << i) < n; ++j)
				t[i+1][j] = f(t[i][j], t[i][j + (1 << i)]);
	}
	ll query(int l, int r) // [l, r)
	{
		int k = __lg(r - l);
		return f(t[k][l], t[k][r - (1 << k)]);
	}
};
struct mn
{
	ll operator () (ll a, ll b) {return min(a, b);}
};
struct gcd
{
	ll operator () (ll a, ll b) {return __gcd(a, b);}
};
st<mn> ST1;
st<gcd> ST2;
void init(int N, long long C[])
{
	A = C;
	n = N;
	ST1.init();
	ST2.init();
}
int query(int L, int R)
{
	return ST1.query(L, R) == ST2.query(L, R);
}
