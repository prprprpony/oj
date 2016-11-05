#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,e) for (auto i = (s), __e = (e); i != __e; ++i)
#define RP(i,e) REP(i,0,e)
template<typename T>
inline void cmax(T & a, T b) {a = max(a, b);}
const int N = 15566, D = __lg(1000000000);
int S;
struct Qry
{
	int i,k,l,r; // [l, r)
	Qry() {}
	Qry(int _i, int _l, int _r) : i(_i), l(_l), r(_r), k(_l / S) {}
	bool operator < (const Qry & rhs) const
	{
		return k < rhs.k || (k == rhs.k && r < rhs.r);
	}
} q[N];
struct node
{
	node * c[2];
} mem[(D + 1) * N];
node * ptr;
node * root;
inline void init() {root = NULL; ptr = mem;}
int qry(node * t, int x, int b)
{
	if (!b)
		return 0;
	int i = (x & b) ? 0 : 1;
	if (t->c[i])
		return b ^ qry(t->c[i], x, b >> 1);
	else
		return qry(t->c[i^1], x, b >> 1);
}
inline int qry(int x) {return root ? qry(root, x, 1 << D) : 0;}
void insert(node *& t, int x, int b)
{
	if (!t)
		t = new (ptr++) node();
	if (!b)
		return;
	int i = (x & b) ? 1 : 0;
	insert(t->c[i], x, b >> 1);
}
inline void insert(int x) {insert(root, x, 1 << D);}
int a[N], ans[N];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	S = sqrt(n+1) + 0.5;
	REP(i,1,n+1) scanf("%d", a + i), a[i] ^= a[i - 1];
	RP(i,m) {int l, r; scanf("%d%d", &l, &r); q[i] = Qry(i,l-1,r+1);}
	sort(q, q + m);
	for (int s = 0, e = 0; s < m; s = e) {
		while (e < m && q[e].k == q[s].k) ++e;
		int ml = 0;
		REP(i,s,e) cmax(ml,q[i].l);
		int ss;
		REP(i,s,e) if (q[i].r > ml) {ss = i; break;}
		int mx = 0, la = ml;
		init();
		REP(i,ss,e) {
			for (; la < q[i].r; ++la) {
				cmax(mx, qry(a[la]));
				insert(a[la]);
			}
			cmax(ans[q[i].i], mx);
			REP(j,q[i].l,ml) cmax(ans[q[i].i], qry(a[j]));
		}
		REP(i,s,e) {
			init();
			REP(j,q[i].l,min(ml,q[i].r)) {
				cmax(ans[q[i].i], qry(a[j]));
				insert(a[j]);
			}
		}
	}
	RP(i,m) printf("%d\n", ans[i]);
}
