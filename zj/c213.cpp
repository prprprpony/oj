#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 87;
struct node
{
	ll s,t;
	ll sum(int l,int r)
	{
		return s + (r - l) * t;
	}
} t[N*4];
void add(int o,int l,int r,int i,int j,int v)
{
	if (r <= i || j <= l)
		return;
	if (i <= l && r <= j) {
		t[o].t += v;
		return;
	}
	int m = (l + r) / 2;
	add(o<<1,l,m,i,j,v);
	add(o<<1|1,m,r,i,j,v);
	t[o].s = t[o<<1].sum(l,m) + t[o<<1|1].sum(m,r);
}
ll qry(int o,int l,int r,int i,int j,ll g=0)
{
	if (r <= i || j <= l)
		return 0;
	g += t[o].t;
	if (i <= l && r <= j)
		return t[o].s + (r-l) * g;
	int m = (l + r) / 2;
	return qry(o<<1,l,m,i,j,g) + qry(o<<1|1,m,r,i,j,g);
}
typedef pair<int,int> pii;
typedef pair<int,pii> pr3;
#define F first
#define S second
vector<pr3> q[N];
pr3 a[N];
ll s[N], ans[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] += s[i-1];
	}
	for (int i = 1; i <= m; ++i) {
		int l,r,v;
		cin >> l >> r >> v;
		--l;
		a[i] = {v,{l,r}};
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		int l,r,vl,vr;
		cin >> l >> r >> vl >> vr;
		--l;
		ans[i] = s[r] - s[l];
		q[vl-1].push_back({-i,{l,r}});
		q[vr].push_back({i,{l,r}});
	}
	for (int i = 1; i <= m; ++i) {
		int v;	
		pii p;
		tie(v,p) = a[i];
		add(1,0,n,p.F,p.S,v);
		for (auto & x : q[i]) {
			tie(v,p) = x;
			ans[abs(v)] += (v>0?1:-1) * qry(1,0,n,p.F,p.S);
		}
	}
	for (int i = 1; i <= k; ++i)
		cout << ans[i] << '\n';
}
