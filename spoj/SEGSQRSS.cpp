#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.12e6;
const int inf = 1e9;
typedef long long ll;
int A[maxn];
struct node
{
	ll s, ss;
	ll at, st;
	node() {}
	node(int v) : s(v), ss(v * v), at(inf), st(inf) {}
};
node t[maxn * 4];
inline void fill(int o, int l, int r, ll x)
{
	t[o].st = x;
	t[o].at = inf;
	int len = r - l + 1;
	t[o].s = x * len;
	t[o].ss = x * x * len;
}
inline void add(int o, int l, int r, ll x)
{
	if (t[o].st != inf) {
		fill(o, l, r, t[o].st + x);
		return;
	}
	if (t[o].at == inf)
		t[o].at = 0;
	t[o].at += x;
	int len = r - l + 1;
	t[o].ss += 2 * x * t[o].s + x * x * len;
	t[o].s += x * len;
}
inline void pull(int o)
{
	t[o].s = t[o + o + 1].s + t[o + o + 2].s;
	t[o].ss = t[o + o + 1].ss + t[o + o + 2].ss;
}
inline void push(int o, int l, int r)
{
	int m = l + ((r - l) >> 1);
	if (t[o].st != inf) {
		fill(o + o + 1, l, m, t[o].st);
		fill(o + o + 2, m + 1, r, t[o].st);
		t[o].st = inf;
	} else if (t[o].at != inf) {
		add(o + o + 1, l, m, t[o].at);
		add(o + o + 2, m + 1, r, t[o].at);
		t[o].at = inf;
	}
}
void build(int o, int l, int r) // [l,r]
{
	if (l == r) {
		t[o] = node(A[l]);
		return;
	}
	int m = l + ((r - l) >> 1);
	build(o + o + 1, l, m);
	build(o + o + 2, m + 1, r);
	t[o] = node(0);
	pull(o);
}
ll query(int o, int l, int r, int i, int j)
{
	if (r < i || j < l)
		return 0;
	if (i <= l && r <= j)
		return t[o].ss;
	push(o, l, r);
	int m = l + ((r - l) >> 1);
	return query(o + o + 1, l, m, i, j) + query(o + o + 2, m + 1, r, i, j);
}
void add(int o, int l, int r, int i, int j, ll x)
{
	if (r < i || j < l)
		return;
	if (i <= l && r <= j) {
		add(o, l, r, x);
		return;
	}
	int m = l + ((r - l) >> 1);
	push(o, l, r);
	add(o + o + 1, l, m, i, j, x);
	add(o + o + 2, m + 1, r, i, j, x);
	pull(o);
}
void fill(int o, int l, int r, int i, int j, ll x)
{
	if (r < i || j < l)
		return;
	if (i <= l && r <= j) {
		fill(o, l, r, x);
		return;
	}
	int m = l + ((r - l) >> 1);
	push(o, l, r);
	fill(o + o + 1, l, m, i, j, x);
	fill(o + o + 2, m + 1, r, i, j, x);
	pull(o);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int caseno = 1; caseno <= T; ++caseno) {
		int N, Q;
		cin >> N >> Q;
		for (int i = 1; i <= N; ++i)
			cin >> A[i];
		build(0, 1, N); 
		cout << "Case " << caseno << ":\n";
		while (Q--) {
			int c, l, r, x;
			cin >> c;
			switch (c) {
			case 2:
				cin >> l >> r;
				cout << query(0, 1, N, l, r) << '\n';
				break;
			case 1:
				cin >> l >> r >> x;
				add(0, 1, N, l, r, x);
				break;
			case 0:
				cin >> l >> r >> x;
				fill(0, 1, N, l, r, x);
				break;
			}
		}
	}
}
