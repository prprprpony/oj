#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 2e9;
struct node
{
	int cov;
	node * lc, * rc;
	node() {}
	node(int v) : cov(v), lc(NULL), rc(NULL) {} 
};
node * t[2]; // t0:rows, t1:cols
inline int val(node * o) {return o ? o->cov : 0;}
int qry(node * o, int l, int r, int i)
{
	if (!o || l == r)
		return val(o);
	int m = l + ((r-l)>>1);
	if (i <= m)
		return max(o->cov, qry(o->lc, l, m, i));
	else
		return max(o->cov, qry(o->rc, m+1, r, i));
}
void upt(node *& o, int l, int r, int i, int j, int v)
{
	if (j < l || r < i)
		return;
	if (!o)
		o = new node(0);
	if (o->cov >= v)
		return;
	if (i <= l && r <= j) {
		o->cov = max(o->cov, v);
		return;
	}
	int m = l + ((r-l)>>1);
	upt(o->lc, l, m, i, j, v);
	upt(o->rc, m+1, r, i, j, v);
}
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	while (q--) {
		int x, y;
		char d;
		scanf("%d %d %c", &x, &y, &d);
		int b = d == 'L' ? 0 : 1;
		if (b)
			swap(x, y);
		int h = qry(t[b], 1, n, y);
		upt(t[b], 1, n, y, y, x);
		if (h < x)
			upt(t[b^1], 1, n, h + 1, x, y);
		printf("%d\n", x - h);
	}
}
