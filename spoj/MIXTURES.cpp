#include <iostream>
#define MAXN 106
#define M 100
#define INF (int)1e9
using namespace std;
int c[MAXN];
int p[MAXN];
int dp[MAXN][MAXN]; // dp(len, start_pos)
inline int color(int len, int s) {
    return (p[s + len - 1] - p[s-1] + M) % M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            p[i] = (p[i-1] + c[i]) % M;
        }
        for (int len = 2; len <= n; len++) {
            for (int s = 1; s <= n - len + 1; s++) {
                dp[len][s] = INF;
                for (int l = 1; l < len; l++) {
                    dp[len][s] = min(dp[len][s], dp[l][s] + dp[len - l][s+l] + color(l, s) * color(len - l, s + l));
                }
            }
        }
        cout << dp[n][1] << '\n';
    }
    
    return 0;
}
