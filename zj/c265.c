/* -std=c99 */
#include <stdio.h>
#define K 51
#define P 15
#define N ((int)1e5 + 87)
const int p[P] = {32,27,25,49,11,13,17,19,23,29,31,37,41,43,47};
int gcd(int a,int b) {return b ? gcd(b,a%b) : a;}

int d[K][4][2], p10[N * 4][P];
typedef struct
{
	int w, v[P];
} node;
typedef struct
{
	int x,y;
} pii;
node t[4*N];
int a[N];
void asn(int o,int x)
{
	for (int i = 0; i < P; ++i)
		t[o].v[i] = x % p[i];
	t[o].w = 0;
	do {
		t[o].w++;
	} while (x/=10);
}
void pull(int o)
{
	t[o].w = t[o<<1].w + t[o<<1|1].w;
	for (int i = 0; i < P; ++i)
		t[o].v[i] = (t[o<<1].v[i] * p10[t[o<<1|1].w][i] % p[i] + t[o<<1|1].v[i]) % p[i];
}
void bld(int o,int l,int r)
{
	if (r - l == 1) {
		asn(o,a[l]);
		return;
	}
	int m = (l + r) / 2;
	bld(o<<1,l,m);
	bld(o<<1|1,m,r);
	pull(o);
}
void upd(int o,int l,int r,int i,int v)
{
	if (r - l == 1) {
		asn(o,v);
		return;
	}
	int m = (l + r) / 2;
	if (i < m)
		upd(o<<1,l,m,i,v);
	else
		upd(o<<1|1,m,r,i,v);
	pull(o);
}
pii meld(pii l, pii r,int x)
{

	return (pii) {l.x + r.x, (l.y * p10[r.x][x] % p[x] + r.y) % p[x]};
}
pii qry(int o,int l,int r,int i,int j,int x)
{
	if (i <= l && r <= j)
		return (pii) {t[o].w, t[o].v[x]};
	int m = (l + r) / 2;
	if (j <= m)
		return qry(o<<1,l,m,i,j,x);
	if (i >= m)
		return qry(o<<1|1,m,r,i,j,x);
	return meld(qry(o<<1,l,m,i,j,x), qry(o<<1|1,m,r,i,j,x), x);
}
int main()
{
	for (int i = 1; i < K; ++i) {
		int x = 0;
		for (int j = 0; j < P; ++j) {
			int g = gcd(i,p[j]);
			if (g > 1) {
				d[i][x][0] = j;
				d[i][x][1] = g;
				++x;
			}
		}
	}
	for (int i = 0; i < N * 4; ++i)
		for (int j = 0; j < P; ++j)
			p10[i][j] = i ? p10[i-1][j] * 10 % p[j] : 1;
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	bld(1,0,n);
	while (q--) {
		int t,l,r,v;
		scanf("%d%d",&t,&l);
		--l;
		if (t == 1) {
			scanf("%d",&v);
			upd(1,0,n,l,v);
		} else {
			scanf("%d%d",&r,&v);
			int no = 0;
			for (int i = 0; d[v][i][1]; ++i)
				no |= qry(1,0,n,l,r,d[v][i][0]).y % d[v][i][1];
			puts(no ? "NO" : "YES");
		}
	}
}
