#include<bits/stdc++.h>
using namespace std;
#define MS(a,v) memset((a),(v),sizeof(a))
template<class T, class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}
/**/
const int N = 106, W = 8, inf=0x3f3f3f3f;
int a[N], dp[2][N][1<<W][W];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;
	while ((cin >> n >> k) && n) {
		int all = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] -= 25;
			all |= 1<<a[i];
		}
		MS(dp[1],0x3f);
		dp[1][0][0][0] = 0;
		for (int i = 0; i < n; ++i) {
			MS(dp[i&1],0x3f);
			for (int j = 0; j <= min(i, k); ++j)
				for (int s = 0; s < (1<<W); ++s) {
					for (int t = 0; t < W; ++t) {
						int pr = dp[i&1^1][j][s][t];
						if (pr != inf) {
							if (s && a[i] == t)
								cmin(dp[i&1][j][s][t],  pr);
							else {
								cmin(dp[i&1][j][1<<a[i]|s][a[i]], pr + 1);
								if (j + 1 <= k)
									cmin(dp[i&1][j+1][s][t], pr);
							}
						}
					}
				}
		}
		int ans = inf;
		for (int j = 0; j <= min(n, k); ++j)
			for (int s = 0; s < (1<<W); ++s)
				for (int t = 0; t < W; ++t) 
					cmin(ans, dp[n&1^1][j][s][t] + __builtin_popcount(all ^ s));
		static int kase;
		cout << "Case " << ++kase << ": " << ans << "\n\n";
	}
}
