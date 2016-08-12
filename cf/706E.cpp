#include <cstdio>
#include <random>
#include <algorithm>
using namespace std;
const int maxn = 1<<10;
int n, m;
struct node
{
	int v;
	node *l, *r, *u, *d;
};
node t[maxn][maxn];
node * getpos(int r, int c)
{
	node * ret;
	int i;
	for (ret = t[r], i = 0; i < c; ret = ret->r, ++i);
	return ret;
}
void link_v(node * a, node * b)
{
	if (a)
		a->d = b;
	if (b)
		b->u = a;
}
void link_h(node * a, node * b)
{
	if (a)
		a->r = b;
	if (b)
		b->l = a;
}
int main()
{
	int q;
	scanf("%d%d%d", &n, &m, &q);
	for (int r = 1; r <= n; ++r) {
		t[r][0].r = &t[r][1];
		t[r][m+1].l = &t[r][m];
	}
	for (int c = 1; c <= m; ++c) {
		t[0][c].d = &t[1][c];
		t[n+1][c].u = &t[n][c];
	}
	for (int r = 1; r <= n; ++r)
		for (int c = 1; c <= m; ++c) {
			scanf("%d", &t[r][c].v);
			t[r][c].l = &t[r][c-1];
			t[r][c].r = &t[r][c+1];
			t[r][c].u = &t[r-1][c];
			t[r][c].d = &t[r+1][c];
		}
	while (q--) {
		int a,b,c,d,h,w;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h,&w);
		node *s1 = getpos(a, b), *s2 = getpos(c, d);
		for (int i = 0; i < w; ++i) {
			if (i)
				s1 = s1->r, s2 = s2->r;
			node *u1 = s1->u, *u2 = s2->u;
			link_v(u1, s2);
			link_v(u2, s1);
		}
		for (int i = 0; i < h; ++i) {
		   	if (i)
				s1 = s1->d, s2 = s2->d;
			node *r1 = s1->r, *r2 = s2->r;
			link_h(s2, r1);
			link_h(s1, r2);
		}
		for (int i = 0; i < w; ++i) {
		   	if (i)
				s1 = s1->l, s2 = s2->l;
			node *d1 = s1->d, *d2 = s2->d;
			link_v(s2, d1);
			link_v(s1, d2);
		}	
		for (int i = 0; i < h; ++i) {
			if (i)
				s1 = s1->u, s2 = s2->u;
			node *l1 = s1->l, *l2 = s2->l;
			link_h(l1, s2);
			link_h(l2, s1);
		}
	}
	node * s = getpos(1,1);
	for (int r = 1; r <= n; ++r, s = s->d) {
		node * o = s;
		for (int c = 1; c <= m; ++c, o = o->r)
			printf("%d%c", o->v, c == m ? '\n' : ' ');
	}
}

