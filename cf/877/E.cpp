#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
typedef pair<int,int> pii;
#define F first
#define S second
/*>_<*/
const int N = 2e5 + 28, inf = 0x3f3f3f3f;
vector<int> g[N];
int a[N], n, tp;
pii rg[N];
struct node
{
	unsigned s:31;
	unsigned tg:1;
} t[N * 4];
void dfs(int u)
{
	rg[u].F = tp++;
	for (int v : g[u])
		dfs(v);
	rg[u].S = tp;
}
inline void pull(int o)
{
	t[o].s = t[o<<1].s + t[o<<1|1].s;
}
inline void fap(int o,int l,int r)
{
	t[o].tg ^= 1;
	t[o].s = r - l - t[o].s;
}
inline void push(int o,int l,int m,int r)
{
	if (t[o].tg) {
		fap(o<<1,l,m);
		fap(o<<1|1,m,r);
		t[o].tg = 0;
	}
}
void bld(int o=1,int l=0,int r=n)
{
	if (r - l == 1) {
		t[o].s = a[l];
		return;
	}
	int m = l + ((r-l)>>1);
	bld(o<<1,l,m);
	bld(o<<1|1,m,r);
	pull(o);
}
void upd(int i,int j,int o=1,int l=0,int r=n)
{
	if (j <= l || r <= i)
		return;
	if (i <= l && r <= j) {
		fap(o,l,r);
		return;
	}
	int m = (l + r) / 2;
	push(o,l,m,r);
	upd(i,j,o<<1,l,m);
	upd(i,j,o<<1|1,m,r);
	pull(o);
}
int qry(int i,int j,int o=1,int l=0,int r=n)
{
	if (j <= l || r <= i)
		return 0;
	if (i <= l && r <= j)
		return t[o].s;
	int m = (l + r) / 2;
	push(o,l,m,r);
	return qry(i,j,o<<1,l,m) + qry(i,j,o<<1|1,m,r);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
		cin >> a[rg[i].F];
	bld();
	int q;
	cin >> q;
	while (q--) {
		string s;
		int v;
		cin >> s >> v;
		if (s[0] == 'p')
			upd(rg[v].F,rg[v].S);
		else 
			cout << qry(rg[v].F,rg[v].S) << '\n';
	}
}
