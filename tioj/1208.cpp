#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20225;
const int maxd = __lg(maxn) + 2;
int mt[maxd][maxn];
int a[maxn];
int n, k;
void build(int d, int l, int r) // [l,r]
{
	if (l == r) {
		mt[d][l] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(d+1, l, m);
	build(d+1, m+1, r);
	merge(mt[d+1]+l, mt[d+1]+m+1, mt[d+1]+m+1, mt[d+1]+r+1, mt[d]+l);
}
int query(int v, int d, int l, int r)
{
	if (l == r)
		return 0;
	int m = (l + r) / 2;
	int ans = query(v, d+1, l, m) + query(v, d+1, m+1, r);
	int j = m + 1;
	for (int i = l; i <= m && j <= r; ++i) {
		for ( ; j <= r && mt[d+1][j] - mt[d+1][i] <= v; ++j);
		ans += r - j + 1;
	}
	return ans;
}
bool ok(int v)
{
	return query(v, 0, 0, n) + 1 <= k;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ((cin >> n >> k) && n) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
		build(0, 0, n);
		ll low = -10000 * n, high = 10000 * n;
		while (low <= high) {
			int mid = low + ((high - low) >> 1);
			if (ok(mid))
				high = mid - 1;
			else
				low = mid + 1;
		}
		cout << low << '\n';
	}
}
