#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2.28e5;
typedef pair<ll,ll> pll;
#define F first
#define S second
ll a[maxn];
pll rng[58 + maxn]; // [S, F]
int pr[maxn];
int ans[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (m < n - 1) {
		puts("No");
		return 0;
	}
	ll l[2], r[2];
	for (int i = 0; i < n; ++i) {
		int j = i & 1;
		scanf("%lld%lld", l + j , r + j);
		if (i) {
			rng[i-1] = {r[j] - l[j^1],  l[j] - r[j^1]};
			// l[j] - r[j^1] <= a[ans[i-1]] <= r[j] - l[j^1]
			pr[i-1] = i-1;
		}
	}
	set<pll> s;
	for (int i = 0; i < m; ++i) {
		scanf("%lld", a + i);
		s.insert({a[i], i});
	}
	--n;
	sort(pr, pr + n, [&] (int x, int y) -> bool {return rng[x] < rng[y];});
	int i;
	for (i = 0; i < n; ++i) {
		auto lb = s.lower_bound({rng[pr[i]].S, -87});
		if (lb == s.end() || lb->F > rng[pr[i]].F)
			break;
		ans[pr[i]] = lb->S;
		s.erase(lb);
	}
	if (i < n) {
		puts("No");
	} else {
		puts("Yes");
		for (int i = 0; i < n; ++i)
			printf("%d%c", ans[i] + 1, i == n - 1 ? '\n' : ' ');
	}
}
