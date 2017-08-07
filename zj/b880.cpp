#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 6, inf = 1e9 + 87;
struct node
{
	int ym,mv,tg;
} t[N*4];
int x[N],y[N];
void bld(int o,int l,int r)
{
	if (r - l == 1) {
		t[o] = {y[l],x[l]+y[l],inf};
		return ;
	}
	int m = l + ((r-l)>>1);
	bld(o<<1,l,m);
	bld(o<<1|1,m,r);
	t[o] = {min(t[o<<1].ym,t[o<<1|1].ym),min(t[o<<1].mv,t[o<<1|1].mv),inf};
}
int qry(int o)
{
	return min(t[o].mv, t[o].tg + t[o].ym);
}
void upd(int o,int l,int r,int i,int j,int v)
{
	if (r <= i || j <= l || v >= t[o].tg)
		return;
	if (i <= l && r <= j) {
		t[o].tg = v;
		return;
	}
	int m = (l + r)>>1;
	upd(o<<1,l,m,i,j,v);
	upd(o<<1|1,m,r,i,j,v);
	t[o].mv = min(qry(o<<1),qry(o<<1|1));
}
int qry(int o,int l,int r,int i,int j,int v = inf)
{
	if (r <= i || j <= l)
		return inf<<1;
	v = min(v, t[o].tg);
	if (i <= l && r <= j)
		return min(t[o].mv, v + t[o].ym);
	int m = (l + r)>>1;
	return min(qry(o<<1,l,m,i,j,v),qry(o<<1|1,m,r,i,j,v));
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", x + i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", y + i);
	bld(1,1,n+1);
	scanf("%d",&m);
	while (m--) {
		char c;
		int l,r,d;
		scanf(" %c%d%d",&c,&l,&r);
		if (c == 'q') {
			printf("%d\n",qry(1,1,n+1,l,r+1));
		} else {
			scanf("%d",&d);
			upd(1,1,n+1,l,r+1,d);
		}
	}
}
