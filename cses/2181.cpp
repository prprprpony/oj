#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp[1005][11][1 << 10];
int main()
{
    int n, m;
    cin >> n >> m;
    swap(n, m);
    dp[0][m - 1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        // (i - 1, m - 1) => (i, 0)
        for (int s = 0; s < (1 << m); ++s)
            if (s & 1) { //不用放
                (dp[i][0][s / 2] += dp[i - 1][m - 1][s]) %= MOD;
            } else { //要放
                if (m >= 2 && (s & 3) == 0)
                    (dp[i][0][s / 2 + 1] += dp[i - 1][m - 1][s]) %= MOD; //橫放
                (dp[i][0][s / 2 + (1 << (m - 1))] += dp[i - 1][m - 1][s]) %= MOD; //直放
            }
        // (i, j) => (i, j + 1)
        for (int j = 0; j + 1 < m; ++j) {
            for (int s = 0; s < (1 << m); ++s) {
                if (s & 1) { //不用放
                    (dp[i][j + 1][s / 2] += dp[i][j][s]) %= MOD;
                } else { //要放
                    if (j + 2 < m && (s & 3) == 0)
                        (dp[i][j + 1][s / 2 + 1] += dp[i][j][s]) %= MOD; //橫放
                    (dp[i][j + 1][s / 2 + (1 << (m - 1))] += dp[i][j][s]) %= MOD; //直放
                }
            }
        }
    }
    cout << dp[n][m - 1][0] << '\n';
}
