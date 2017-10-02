#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define F first
#define S second
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
template<class T,class U>
bool cmax(T & a,const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a,const U & b) {return a > b ? a = b, 1 : 0;}
/* */
const int N = 1.2e5 + 87;
const int C = 1e6 + 87;
struct edge
{
	int u, v, c;
	int to(int x) {return u ^ v ^ x;}
} e[N];
struct node
{
	vi v;
	node * lc, * rc;
} * rt[C];
struct
{
	ll f[N+1];
	void add(int i,ll v)
	{
		for ( ; i <= N; i += i & -i)
			f[i] += v;
	}
	void add(int i,int j, ll v)
	{
		add(i,v);
		add(j,-v);
	}
	ll qry(int i)
	{
		ll r = 0;
		for (; i; i ^= i & -i)
			r += f[i];
		return r;
	}
} fen;
int la[N], q, pa[N], sz[N], nc;
vector<pair<int,pii>> qr[C];
pair<int,pii> qrx[N];
vector<ll> ans;
ll su = 0;
void add(node *& t,int l,int r,int i,int j,int x)
{
	if (r <= i || j <= l)
		return;
	if (!t)
		t = new node();
	if (i <= l && r <= j) {
		if (x)
			t->v.PB(x);
		return;
	}
	int m = (l + r) / 2;
	add(t->lc, l, m, i, j, x);
	add(t->rc, m, r, i, j, x);
}
void add(int c,int i,int j,int x)
{
	add(rt[c], 1, q+1, i, j, x);
}
int find(int x) {return x == pa[x] ? x : find(pa[x]);}
void meld(int a,int b, vector<pii> & h)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] > sz[b])
		swap(a,b);
	pa[a] = b;
	su += sz[a] * 1LL * sz[b];
	sz[b] += sz[a];
	h.PB({b,a});
}
void go(node * t,int l = 1, int r = q + 1)
{
	if (!t) {
		fen.add(l,r,su);
		return;
	}
	vector<pii> hs;
	for (int i : t->v)
		meld(e[i].u, e[i].v, hs);
	if (r - l == 1) {
		fen.add(l,r,su);
		const auto & p = qrx[l];
		if (p.F == nc) {
			ll x = sz[find(e[p.S.F].u)];
			ans[p.S.S] += x * (x - 1) / 2;
		}
	} else {
		int m = (l + r) / 2;
		go(t->lc,l,m);
		go(t->rc,m,r);
	}
	for (;SZ(hs);hs.pop_back()) {
		int b, a;
		tie(b,a) = hs.back();
		sz[b] -= sz[a];
		su -= sz[a] * 1LL * sz[b];
		pa[a] = a;
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; ++i)
		cin >> e[i].u >> e[i].v >> e[i].c;
	cin >> q;
	for (int t = 1; t <= q; ++t) {
		int ty;
		cin >> ty;
		if (ty == 1) {
			int i, c;
			cin >> i >> c;
			if (e[i].c == c)
				continue;
			add(e[i].c, la[i], t, i);
			e[i].c = c;
			la[i] = t;
		} else if (ty == 2) {
			int l, r;
			cin >> l >> r;
			qr[r].PB({t, {-2,SZ(ans)}});
			qr[l-1].PB({t, {-1,SZ(ans)}});
			ans.PB(0);
		} else {
			int i;
			cin >> i;
			add(e[i].c, t, t + 1, 0);
			qrx[t] = {e[i].c, {i,SZ(ans)}};
			ans.PB(0);
		}
	}
	for (int i = 1; i <= n - 1; ++i)
		add(e[i].c, la[i], q + 1, i);
	for (int i = 1; i <= n; ++i)
		pa[i] = i, sz[i] = 1;
	for (int i = 1; i < C; ++i) {
		nc = i;
		go(rt[i]);
		for (const auto & p : qr[i])
			ans[p.S.S] += (p.S.F == -1 ? -1 : 1) * fen.qry(p.F);
	}
	for (int i = 0; i < SZ(ans); ++i)
		cout << ans[i] << '\n';
}
