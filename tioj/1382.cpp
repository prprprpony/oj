#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.12e5;
mt19937 mt(1925);
struct node
{
	int v, p, sz;
	node * lc, * rc;
	node() {}
	node(int k) : v(k), p(mt()), sz(1), lc(NULL), rc(NULL) {}
};
node mem[maxn];
inline int SZ(node * t) {return t ? t->sz : 0;}
inline void pull(node * t)
{
	if (t)
		t->sz = SZ(t->lc) + 1 + SZ(t->rc);
}
void split(node * t, int k, node *& a, node *& b)
{
	if (!t) {
		a = b = NULL;
		return;
	}
	if (SZ(t->lc) + 1 <= k) {
		a = t;
		split(t->rc, k - SZ(t->lc) - 1, a->rc, b);
		pull(a);
	} else {
		b = t;
		split(t->lc, k, a, b->lc);
		pull(b);
	}
}
node * meld(node * a, node * b)
{
	if (!a || !b)
		return a ? a : b;
	if (a->p > b->p) {
		a->rc = meld(a->rc, b);
		pull(a);
		return a;
	} else {
		b->lc = meld(a, b->lc);
		pull(b);
		return b;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		node * rt = NULL;
		for (int i = 1; i <= n; ++i) {
			mem[i] = node(i);
			rt = meld(rt, mem + i);
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			cnt = (cnt + a - 1) % SZ(rt);
			node * l, * m, * r;
			split(rt, cnt, l, r);
			split(r, 1, m, r);
			cout << m->v << (i != n - 1 ? ' ' : '\n');
			rt = meld(l, r);
		}
	}

}
