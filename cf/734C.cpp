#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,e) for (auto i = (s), __e = (e); i != __e; ++i)
typedef long long ll;
const int M = 2.28e5;
ll a[M], b[M], c[M], d[M];
int main()
{
	int n, m, k, x, s;
	scanf("%d%d%d%d%d", &n, &m, &k, &x, &s);
	ll ans = n * 1LL * x;
	a[0] = x;
	b[0] = 0;
	++m;
	REP(i,1,m)
		scanf("%lld", a + i);
	REP(i,1,m)
		scanf("%lld", b + i);
	REP(i,0,k)
		scanf("%lld", c + i);
	REP(i,0,k)
		scanf("%lld", d + i);
	REP(i,0,m) {
		if (s < b[i])
			continue;
		int	j = upper_bound(d, d + k, s - b[i]) - d - 1;
		ans = min(ans, (n - (j >= 0 ? c[j] : 0)) * a[i]);
	}
	printf("%lld\n", ans);
}
