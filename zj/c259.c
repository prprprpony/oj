#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef long long ll;
#define N ((int)3e5 + 1987)
#define INF ((ll)1e13)
#define MAX(a,b) ((a)<(b)?(b):(a))
#define CMAX(a,b) (a)=MAX((a),(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CMIN(a,b) (a)=MIN((a),(b))
struct nd
{
	ll mn, se, su, tg;
	int ct;
} t[N * 4];
ll a[N];
void pull(int o)
{
	t[o].mn = MIN(t[o<<1].mn, t[o<<1|1].mn);
	t[o].ct = 0;
	t[o].se = INF;
	t[o].su = t[o<<1].su + t[o<<1|1].su;
	if (t[o].mn == t[o<<1].mn) {
		t[o].ct += t[o<<1].ct;
		if (t[o<<1].se != t[o].mn)
			CMIN(t[o].se, t[o<<1].se);
	} else {
		CMIN(t[o].se, t[o<<1].mn);
	}
	if (t[o].mn == t[o<<1|1].mn) {
		t[o].ct += t[o<<1|1].ct;
		if (t[o<<1|1].se != t[o].mn)
			CMIN(t[o].se, t[o<<1|1].se);
	} else {
		CMIN(t[o].se, t[o<<1|1].mn);
	}
	if (t[o].se == INF)
		t[o].se = t[o].mn;
}
void bld(int o,int l,int r)
{
	if (r-l == 1) {
		t[o].mn = t[o].se = t[o].su = a[l];
		t[o].ct = 1;
		return;
	}
	int m = (l + r) / 2;
	bld(o<<1,l,m);
	bld(o<<1|1,m,r);
	pull(o);
}
void dtg(int o,ll v)
{
	t[o].tg = v;
	t[o].su += t[o].ct * (v - t[o].mn);
	if (t[o].mn == t[o].se)
		t[o].se = v;
	t[o].mn = v;
}
void push(int o)
{
	if (t[o].tg) {
		if (t[o<<1].mn < t[o].tg)
			dtg(o<<1,t[o].tg);
		if (t[o<<1|1].mn < t[o].tg)
			dtg(o<<1|1,t[o].tg);
		t[o].tg = 0;
	}
}
void upd(int o,int l,int r,int i,int j,ll v)
{
	if (r <= i || j <= l || v <= t[o].mn)
		return;
	if (i <= l && r <= j && (t[o].ct == r - l || v < t[o].se)) {
		dtg(o,v);
		return;
	}
	int m = (l + r) / 2;
	push(o);
	upd(o<<1,l,m,i,j,v);
	upd(o<<1|1,m,r,i,j,v);
	pull(o);
}
ll qry(int o,int l,int r,int i,int j)
{
	if (r <= i || j <= l)
		return 0;
	if (i <= l && r <= j)
		return t[o].su;
	int m = (l + r) / 2;
	push(o);
	return qry(o<<1,l,m,i,j) + qry(o<<1|1,m,r,i,j);
}
int main(void)
{
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i)
		scanf("%lld",a + i);
	bld(1,0,n);
	while (m--) {
		int t, l, r;
		scanf("%d%d%d",&t,&l,&r);
		--l;
		if (t == 1) {
			ll v;
			scanf("%lld",&v);
			upd(1,0,n,l,r,v);
		} else {
			printf("%lld\n", qry(1,0,n,l,r));
		}
	}
	return 0;
}
