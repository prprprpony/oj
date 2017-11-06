#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
template<class T>
T gcd(T a,T b)
{
	T t;
	while (b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
/*>_<*/
const int N = 1e5 + 87, inf = 1e9 + 87;
int a[N], n, q;
struct node
{
	int g, rt, tg;
	ll rs;
} t[N * 4];
#define LC o<<1,l,m
#define RC o<<1|1,m,r
void bld(int o = 1, int l = 0, int r = n)
{
	if (r - l == 1) {
		t[o].g = a[l];
		return;
	}
	int m = l + ((r - l)>>1);
	bld(LC);
	bld(RC);
	t[o].g = gcd(t[o<<1].g, t[o<<1|1].g);
}
void chg(int i,int v,int o = 1, int l = 0, int r = n)
{
	if (r - l == 1) {
		t[o].g = a[l] = v;
		return;
	}
	int m = l + ((r - l)>>1);
	if (i < m)
		chg(i,v,LC);
	else
		chg(i,v,RC);
	t[o].g = gcd(t[o<<1].g, t[o<<1|1].g);
}
void gr(pii & p,int o = 1, int l = 0, int r = n)
{
	if (l == p.F) {
		int g = gcd(p.S, t[o].g);
		if (g > 1) {
			p = {r, g};
			return;
		}
	}
	if (r - l == 1)
		return;
	int m = l + ((r - l)>>1);
	if (p.F < m) {
		gr(p,LC);
		if (p.F == m)
			gr(p,RC);
	} else {
		gr(p,RC);
	}
}
int grr(int i)
{
	pii p(i,0);
	gr(p);
	return p.F;
}
void gl(pii & p,int o = 1, int l = 0, int r = n)
{
	if (r == p.F) {
		if (t[o].g % p.S == 0) {
			p.F = l;
			return;
		}
	}
	if (r - l == 1)
		return;
	int m = l + ((r - l)>>1);
	if (p.F <= m) {
		gl(p,LC);
	} else {
		gl(p,RC);
		if (p.F == m)
			gl(p,LC);
	}
}
void aso(int o,int l,int r,int v)
{
	t[o].tg = 1;
	t[o].rs = (r - l) * 1LL * v;
	t[o].rt = v;
}
void push(int o,int l,int m,int r)
{
	if (t[o].tg) {
		aso(LC,t[o].rt);
		aso(RC,t[o].rt);
		t[o].tg = 0;
	}
}
void pull(int o)
{
	t[o].rs = t[o<<1].rs + t[o<<1|1].rs;
	t[o].rt = t[o<<1|1].rt;
}
void asn(int i,int j,int v,int o = 1, int l = 0, int r = n)
{
	if (j <= l || r <= i)
		return;
	if (i <= l && r <= j) {
		aso(o,l,r,v);
		return;
	}
	int m = l + ((r - l)>>1);
	push(o,l,m,r);
	asn(i,j,v,LC);
	asn(i,j,v,RC);
	pull(o);
}
void init()
{
	bld();
	for (int i = 0; i < n; ++i)
		asn(i,i+1,grr(i));
}
void upd(int i,int v)
{
	chg(i,v);
	asn(i,i+1,grr(i));
	pii la(i,0);
	while (la.F > 0) {
		pii p(i, gcd(a[la.F-1],la.S));
		if (p.S == 1)
			break;
		gl(p);
		asn(p.F,la.F,grr(p.F));
		la = p;
	}
}
int bs(int i,int j,int o = 1, int l = 0, int r = n)
{
	if (r - l == 1) 
		return t[o].rt <= j ? r : i;
	int m = l + ((r - l)>>1);
	push(o,l,m,r);
	if (m < i)
		return bs(i,j,RC);
	if (j <= m)
		return bs(i,j,LC);
	if (t[o<<1].rt <= j)
		return max(m, bs(i,j,RC));
	else
		return bs(i,j,LC);
}
ll sum(int i,int j,int o = 1, int l = 0, int r = n)
{
	if (j <= l || r <= i)
		return 0;
	if (i <= l && r <= j)
		return t[o].rs;
	int m = l + ((r - l)>>1);
	push(o,l,m,r);
	return sum(i,j,LC) + sum(i,j,RC);
}
ll qry(int l,int r)
{
	int k = bs(l,r);
	return sum(l,k) - (l + k - 1) * 1LL * (k - l) / 2 + (r - k + 1) * 1LL * (r - k) / 2;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	init();
	while (q--) {
		int ty;
		cin >> ty;
		if (ty == 1) {
			int i,v;
			cin >> i >> v;
			--i;
			upd(i,v);
		} else {
			int l,r;
			cin >> l >> r;
			--l;
			cout << qry(l,r) << '\n';
		}
	}
}
