#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for (auto i = (s), __e = (e); i != __e; ++i)
template <typename T>
inline void cmax(T & a, T b) {a = max(a, b);}
template <typename T>
inline void cmin(T & a, T b) {a = min(a, b);}
const int N = 55566, M = 5566, D = __lg(1000000), INF = 1e9;
// Mo's algorithm
int S = 689;
struct Qry
{
	int i,k,l,r;
	Qry() {}
	Qry(int _i, int _l, int _r) : i(_i), l(_l), r(_r), k(_l / S) {}
	bool operator < (const Qry & x) const
	{
		return k < x.k || (k == x.k && r < x.r);
	}
} q[M];
int ans[M];

// trie
struct node
{
	int mv;
	node * c[2];
	node() {}
	node(int v) : mv(v), c{NULL,NULL} {}
} mem[(D + 1) * N];
node * ptr = mem;
node * trie[2];
void insert0(node *& t, int v, int x, int b)
{
	if (!t)
		t = new (ptr++) node(INF);
	cmin(t->mv, v);
	if (!b)
		return;
	insert0(t->c[(x & b) ? 1 : 0], v, x, b >> 1);
}
void insert0(int v, int x) {insert0(trie[0], v, x, 1 << D);}

void insert1(node *& t, int v, int x, int b)
{
	if (!t)
		t = new (ptr++) node(-INF);
	cmax(t->mv, v);
	if (!b)
		return;
	insert1(t->c[(x & b) ? 1 : 0], v, x, b >> 1);
}
void insert1(int v, int x) {insert1(trie[1], v, x, 1 << D);}

int qry0(node * t, int v, int x, int b)
{
	if (!b)
		return 0;
	int k = (x & b) ? 0 : 1;
	if (t->c[k] && t->c[k]->mv < v)
		return b ^ qry0(t->c[k], v, x, b >> 1);
	else
		return qry0(t->c[k^1], v, x, b >> 1);
}
inline int qry0(int v, int x) {return trie[0] && trie[0]->mv < v ? qry0(trie[0], v, x, 1 << D) : 0;}

int qry1(node * t, int v, int x, int b)
{
	if (!b)
		return 0;
	int k = (x & b) ? 0 : 1;
	if (t->c[k] && t->c[k]->mv > v)
		return b ^ qry1(t->c[k], v, x, b >> 1);
	else
		return qry1(t->c[k^1], v, x, b >> 1);
}
inline int qry1(int v, int x) {return trie[1] && trie[1]->mv > v ? qry1(trie[1], v, x, 1 << D) : 0;}

inline void init()
{
	trie[0] = trie[1] = NULL;
	ptr = mem;
}

inline int f(int v) // f(0, v)
{
	switch (v % 4) {
		case 0: return v;
		case 1: return 1;
		case 2: return v + 1;
		case 3: return 0;
	}
}

int a[N];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	// S = sqrt(n) + 0.5;
	rep(i,0,n)
		scanf("%d", a + i);
	rep(i,0,m) {
		int l, r; 
		scanf("%d%d", &l, &r);
		q[i] = Qry(i, l-1, r);
	}
	sort(q, q + m);
	for (int i = 0, j = 0; i < m; i = j) {
		while (j < m && q[j].k == q[i].k)
			++j;
		int ml = 0;
		rep(k,i,j) cmax(ml, q[k].l);
		int sep;
		rep(k,i,j) if (q[k].r > ml) {sep = k; break;}

		{ // iterate through right end points
			init();
			int mx = 0;
			int last = ml;
			rep(k,sep,j) {
				for (; last < q[k].r; ++last) { // RR
					int v = a[last];
					cmax(mx, v);
					cmax(mx, qry0(v, f(v)));
					cmax(mx, qry1(v-1, f(v-1)));
					insert0(v-1, f(v-1));
					insert1(v, f(v));
				}
				int mmx = mx;
				rep(l,q[k].l,ml) { // LR
					int v = a[l];
					cmax(mmx, v);
					cmax(mmx, qry0(v, f(v)));
					cmax(mmx, qry1(v-1, f(v-1)));
				}
				cmax(ans[q[k].i], mmx);
			}
		}

		rep(k,i,j) { // LL
			init();
			int r = min(ml, q[k].r);
			int mx = 0;
			rep(l,q[k].l,r) {
				int v = a[l];
				cmax(mx, v);
				cmax(mx, qry0(v, f(v)));
				cmax(mx, qry1(v-1, f(v-1)));
				insert0(v-1, f(v-1));
				insert1(v, f(v));
			}
			cmax(ans[q[k].i], mx);
		}
	}
	rep(i,0,m) printf("%d\n", ans[i]);
}
