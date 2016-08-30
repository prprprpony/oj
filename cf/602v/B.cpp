#include <bits/stdc++.h>
#define FOR(i,s,e) for (int i = (s); i < (e); ++i)
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 053;
int a[maxn];
int last[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 1, n+1)
		scanf("%d", a + i);
	int ans = 1;
	int m = a[1], M = a[1];
	for (int l = 1, r = 0; r < n; ) {
		while (M - m <= 1 && ++r <= n) {
			M = max(M, a[r]);
			m = min(m, a[r]);
			last[a[r]] = r;
		}
		ans = max(ans, r - l);
		l = (a[r] == M ? last[a[r] - 2] : last[a[r] + 2]) + 1;
		if (a[r] == M)
			++m;
		else
			--M;
	}
	printf("%d\n", ans);
}
