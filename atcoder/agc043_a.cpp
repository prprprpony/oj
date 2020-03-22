#include<bits/stdc++.h>
using namespace std;
const int N = 105, inf = 1e9;
char s[N][N];
int dp[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= m; ++j)
            s[i][j] = s[i][j] == '#';
    }
    dp[n][m] = s[n][m];
    for (int w = n + m - 1; w >= 2; --w) {
        for (int i = 1; i <= n; ++i) {
            int j = w - i;
            if (j < 1 || j > m)
                continue;
            dp[i][j] = inf;
            if (i + 1 <= n)
                dp[i][j] = min(dp[i][j], (s[i][j] == 1 && s[i + 1][j] == 0) + dp[i + 1][j]);
            if (j + 1 <= m)
                dp[i][j] = min(dp[i][j], (s[i][j] == 1 && s[i][j + 1] == 0) + dp[i][j + 1]);
        }
    }
    cout << dp[1][1] << endl;
}
