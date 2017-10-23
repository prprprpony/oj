#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
/*>_<*/
const int N = 1e5 + 87, inf = 1e9 + 87;
int n,a[N],t[N*4];
int pu(int i,int j) {return a[i] < a[j] ? i : j;}
void pull(int o)
{
	t[o] = pu(t[o<<1], t[o<<1|1]);
}
void bld(int o = 1, int l = 0, int r = n)
{
	if (r - l == 1) {
		t[o] = l;
		return;
	}
	int m = l + ((r-l)>>1);
	bld(o<<1,l,m);
	bld(o<<1|1,m,r);
	pull(o);
}
int qry(int i,int j,int o = 1, int l = 0, int r = n)
{
	if (r <= i || j <= l)
		return n;
	if (i <= l && r <= j)
		return t[o];
	int m = (l + r) / 2;
	return pu(qry(i,j,o<<1,l,m), qry(i,j,o<<1|1,m,r));
}
void upd(int i,int o = 1, int l = 0, int r = n)
{
	if (r - l == 1) {
		t[o] = n;
		return;
	}
	int m = l + ((r-l)>>1);
	if (i < m)
		upd(i,o<<1,l,m);
	else
		upd(i,o<<1|1,m,r);
	pull(o);
}
int DnC(int l = 0, int r = n)
{
	set<pii> s{{r,l}};
	int x = a[qry(l,r)];
	int i;
	while (a[i = qry(l,r)] == x) {
		auto it = s.upper_bound({i,inf});
		if (it != s.end() && it->S <= i) {
			if (it->S < i)
				s.insert({i, it->S});
			if (i+1 < it->F)
				s.insert({it->F, i+1});
			s.erase(it);
		}
		upd(i);
	}
	int ans = 1;
	for (const auto & p : s)
		ans += DnC(p.S,p.F);
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	a[n] = inf;
	bld();
	cout << DnC() << '\n';
}
