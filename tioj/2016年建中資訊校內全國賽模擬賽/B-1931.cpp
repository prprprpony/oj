#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
inline bool RD(int & a) {return scanf("%d", &a) == 1;}

const int maxn = 1.12e5;
int a[maxn];
int main()
{
	int T, N;
	RD(T);
	while (T--) {
		ll ans = 0;
		RD(N);
		RP(i,N)
			RD(a[i]);
		sort(a, a + N);
		for (int i = N - 1; i >= 1; i -= 2)
			ans += 4LL * a[i-1];
		printf("%lld\n", ans);
	}
}
