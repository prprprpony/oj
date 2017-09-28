#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second 
template<class T,class U>
pair<T,U> operator - (const pair<T,U> & a, const pair<T,U> & b)
{
	return {b.F - a.F, b.S - a.S};
}
/**/
const int N = 1e5 + 87, inf = 1e9;
int n,ra[N];
pii t[4*N];
void bld(int o,int l,int r)
{
	if (r - l == 1) {
		t[o] = {ra[l],l};
		return;
	}
	int m = l + ((r - l) >> 1);
	bld(o<<1,l,m);
	bld(o<<1|1,m,r);
	t[o] = min(t[o<<1], t[o<<1|1]);
}
pii qry(int o,int l,int r,int i,int j)
{
	if (r <= i || j <= l)
		return {inf,inf};
	if (i <= l && r <= j)
		return t[o];
	int m = (l + r) / 2;
	return min(qry(o<<1,l,m,i,j),qry(o<<1|1,m,r,i,j));
}
void upd(int o,int l,int r,int i,int v)
{
	if (r - l == 1) {
		t[o].F = v;
		return;
	}
	int m = l + ((r - l) >> 1);
	if (i < m)
		upd(o<<1,l,m,i,v);
	else
		upd(o<<1|1,m,r,i,v);
	t[o] = min(t[o<<1], t[o<<1|1]);
}
int gr(int i)
{
	int lo = i + 1, hi = n;
	while (lo <= hi) {
		int mi = (lo + hi) / 2;
		if (qry(1,1,n+1,i+1,mi+1).F >= ra[i])
			lo = mi + 1;
		else
			hi = mi - 1;
	}
	return lo;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		ra[b] = -a;
	}
	bld(1,1,n+1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ra[i] == inf)
			continue;
		++ans;
		int j = i;
		while (j <= n) {
			int x = gr(j);
			ra[j] = inf;
			upd(1,1,n+1,j,inf);
			j = x;
		}
	}
	cout << ans << '\n';
}
