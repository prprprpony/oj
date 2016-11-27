#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,b) REP(i,0,b)
#define PER(i,a,b) for (int i = (a), __e = (b); i > __e; --i)
#define PR(i,b) REP(i,(b)-1,-1)
#define SZ(a) ((int)a.size())
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
typedef vector<int> vi;

const int maxn = 20, inf = 1e9;
int c[maxn][maxn];
int dp[1 << maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	if (n == k) {
		cout << "0\n";
		return 0;
	}
	RP(i,n)
		RP(j,n)
			cin >> c[i][j];
	int full = (1 << n) - 1;
	int ans = inf;
	PER(s,full-1,(1 << k) - 2) {
		if (__builtin_popcount(s) < k)
			continue;
		dp[s] = inf;
		for (int p = ~s & full, lp; p; p ^= lp) {
			lp = p & -p;
			for (int q = s, lq; q; q ^= lq)  {
				lq = q & -q;
				dp[s] = min(dp[s], dp[s ^ lp] + c[__lg(lp)][__lg(lq)]);
			}
		}
		if (__builtin_popcount(s) == k)
			ans = min(ans, dp[s]);
	}
	cout << ans << '\n';
}
