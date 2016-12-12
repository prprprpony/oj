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

const int maxn = 1.12e5;
pii a[maxn];
int p[maxn << 1];
ll dp[maxn];
struct BIT
{
	int n;
	ll B[maxn << 1];
	void init(int m)
	{
		n = m;
		CZ(B+1,m);
	}
	void add(int i, ll v)
	{
		for ( ; i <= n ; i += i & -i)
			B[i] = max(B[i], v);
	}
	ll qry(int i)
	{
		ll ret = 0;
		for ( ; i; i ^= i & -i)
			ret = max(ret, B[i]);
		return ret;
	}
} f;
int main()
{
	int T;
	RD(T);
	while (T--) {
		int n,l,c;
		RD(n,l,c);
		f.init(2 * n);
		RP(i,n) {
			RD(a[i].S,a[i].F);
			a[i].F += a[i].S;
			p[i + i + 1] = a[i].S;
			p[i + i + 2] = a[i].F;
		}
		sort(a, a + n);
		sort(p+1, p + 2 * n + 1);
		ll ans = 0;
		RP(i,n) {
			int j = lower_bound(p+1, p+2*n+1, a[i].S) - p;
			dp[i] = c - a[i].F + f.qry(j);
			j = lower_bound(p+1, p+2*n+1, a[i].F) - p;
			f.add(j, dp[i]);
			ans = max(ans, dp[i]);
		}
		printf("%lld\n", ans);
	}
}
