#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3.18e5;
ll w[maxn], t[maxn];
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", t + i, w + i);
		a[i] = i;
	}
	sort(a + 1, a + n, [&] (int x, int y) -> bool {
		return t[x] < t[y];
	});
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	int b = n - 1, cnt = 0;
	for ( ; b && t[a[b]] > t[0]; --b, ++cnt)
		pq.push(w[a[b]] - t[a[b]] + 1);
	int ans = cnt + 1;
	while (pq.size() && t[0]) {
		ll u = pq.top();
		pq.pop();
		if (u <= t[0]) {
			t[0] -= u;
			--cnt;
			for ( ; b && t[a[b]] > t[0]; --b, ++cnt)
				pq.push(w[a[b]] - t[a[b]] + 1);
			ans = min(ans, cnt + 1);
		} else {
			break;
		}
	}
	printf("%d\n", ans);
}
