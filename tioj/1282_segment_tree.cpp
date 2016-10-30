#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.12e5;
ll A[maxn];
struct node
{
	ll s, g;
	node() {}
	node(ll v) : s(v), g(v) {};
};
node t[maxn * 4];
inline int LC(int o) {return o + o + 1;}
inline int RC(int o) {return o + o + 2;}
inline void pull(int o)
{
	t[o].s = t[LC(o)].s + t[RC(o)].s;
	t[o].g = __gcd(t[LC(o)].g, t[RC(o)].g);
}
void build(int o, int l, int r)
{
	if (l == r) {
		t[o] = node(A[l]);
		return;
	}
	int m = (l + r) / 2;
	build(LC(o), l, m);
	build(RC(o), m + 1, r);
	pull(o);
}
void add(int o, int l, int r, int i, ll k)
{
	if (l == r) {
		t[o] = node(t[o].s + k);
		return;
	}
	int m = (l + r) / 2;
	if (i <= m)
		add(LC(o), l, m, i, k);
	else
		add(RC(o), m + 1, r, i, k);
	pull(o);
}
ll qs(int o, int l, int r, int i, int j)
{
	if (r < i || j < l)
		return 0;
	if (i <= l && r <= j)
		return t[o].s;
	int m = (l + r) / 2;
	return qs(LC(o), l, m, i, j) + qs(RC(o), m + 1, r, i, j);
}
ll qg(int o, int l, int r, int i, int j)
{
	if (r < i || j < l)
		return 0;
	if (i <= l && r <= j)
		return t[o].g;
	int m = (l + r) / 2;
	return __gcd(qg(LC(o), l, m, i, j), qg(RC(o), m + 1, r, i, j));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = N; i > 1; --i)
		A[i] -= A[i - 1];
	build(0, 1, N);
	while (Q--) {
		int c, l, r;
		ll k;
		cin >> c >> l >> r;
		switch (c) {
		case 1:
			cin >> k;
			add(0, 1, N, l, k);
			if (r < N)
				add(0, 1, N, r+1, -k);
			break;
		case 2:
			cout << abs(__gcd(qs(0, 1, N, 1, l), l < r ? qg(0, 1, N, l+1, r) : 0)) << '\n';
		}
	}
}
