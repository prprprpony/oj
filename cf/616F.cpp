#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = (s); i != (e); ++i)
#define per(i, e, s) for (int i = (e); i != (s); --i)
using namespace std;
typedef long long ll;
const int N = 1.12e5;
const int LEN = 6.4 * N;
int len;
int c[N], sz[N];
int s[LEN], sa[LEN], * rk, ht[LEN], v[2][LEN], ct[LEN], cost[LEN];
ll co[LEN];
void build_sa(int n,int m)
{
	int *x = v[0], *y = v[1];
	fill_n(ct, m, 0);
	rep(i,0,n) ++ct[x[i] = s[i]];
	rep(i,1,m) ct[i] += ct[i-1];
	per(i,n-1,-1) sa[--ct[x[i]]] = i;
	for (int k = 1; k < n; k <<= 1) {
		int p = 0;
		rep(i,n-k,n) y[p++] = i;
		rep(i,0,n) if (sa[i] >= k) y[p++] = sa[i] - k;
		fill_n(ct, m, 0);
		rep(i,0,n) ++ct[x[y[i]]];
		rep(i,1,n) ct[i] += ct[i-1];
		per(i,n-1,-1) sa[--ct[x[y[i]]]] = y[i];
		swap(x,y);
		x[sa[0]] = 0;
		p = 1;
		rep(i,1,n) x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i] + k] == y[sa[i-1] + k] ? p - 1 : p++;
		if ((m = p) == n) {
			rk = x;
			break;
		}
	}
	int h = 0;
	ht[0] = 0;
	rep(i,0,n) {
		if (!rk[i]) {h = 0; continue;}
		while (s[i + h] == s[sa[rk[i] - 1] + h]) ++h;
		ht[rk[i]] = h;
		if (h) --h;
	}
}
int ls[LEN], rs[LEN];
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
typedef int (*func)(int, int);
struct BIT
{
	func f;
	int t[LEN], v;
	void init(func _f, int _v)
   	{
		f = _f;
		v = _v;
		fill_n(t, len + 1, v);
	}
	void add(int i, int x)
	{
		for (; i <= len; i += i & -i)
			t[i] = f(t[i], x);
	}
	int qry(int i)
	{
		int ret = v;
		for ( ; i; i ^= i & -i)
			ret = f(ret, t[i]);
		return ret;
	}
} bit;
int main()
{
	int n;
	scanf("%d ", &n);
	/*
	   [0, n - 1] = nil characters
	   [n, n + 25] = [a, z]
	*/
	len = 0;
	rep (i,0,n) {
		int ch;
		int la = len;
		while ((ch = getchar()) != '\n')
			s[len++] = n + ch - 'a';
		sz[i] = len - la;
		s[len++] = i;
	}
	ll ans = 0;
	rep(i,0,n) scanf("%d", c + i);
	build_sa(len, n + 26);
	int la = 0;
	rep(i,0,n) {
		if (ht[rk[la]] != sz[i] && ht[rk[la]+1] != sz[i])
			ans = max(ans, sz[i] * 1LL * c[i]);
		la += sz[i] + 1;
	}
	int idx = n - 1;
	per(i,len-1,-1) 
		cost[i] = c[idx = min(idx, s[i])];
	rep(i,0,len)
		co[i] = cost[sa[i]];
	rep(i,1,len)
		co[i] += co[i - 1];
	bit.init(max,-1);
	rep(i,0,len) {
		ls[i] = bit.qry(ht[i]);
		bit.add(ht[i] + 1, i);
	}
	bit.init(min,len);
	per(i,len-1,-1) {
		rs[i] = bit.qry(ht[i]);
		bit.add(ht[i] + 1, i);
	}
	rep(i,0,len) if (ht[i])
		ans = max(ans, ht[i] * (co[rs[i]-1] - co[ls[i]-1]));
	printf("%lld\n", ans);
}
