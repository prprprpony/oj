#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define CZ(a,n) memset((a), 0, (n) * sizeof(*(a)))
inline bool RD(void) {return true;}
inline bool RD(int & a) {return scanf("%d", &a) == 1;}
template <typename T, typename ... TT>
inline bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}

const int maxn = 1.12e5, inf = 2e9;
pii a[maxn];
ll dp[maxn];
int main()
{
	int T;
	RD(T);
	while (T--) {
		int n,l,c;
		RD(n,l,c);
		RP(i,n) {
			RD(a[i].S,a[i].F);
			a[i].F += a[i].S;
		}
		sort(a, a + n);
		ll ans = 0;
		RP(i,n) {
			int j = upper_bound(a, a + i, pii{a[i].S, inf}) - a - 1;
			dp[i] = max((i ? dp[i-1] : 0), c - a[i].F + (j >= 0 ? dp[j] : 0));
		}
		printf("%lld\n", dp[n-1]);
	}
}
