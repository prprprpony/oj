#include<bits/stdc++.h>
using namespace std;
const int N = 62, M = 3666;
int x, y, m;
unsigned long long dp[N][N][M], ans;
int main()
{
    cin >> x >> y >> m;
    dp[0][0][0] = 1;
    for (int i = 0; i <= x; ++i)
        for (int j = 0; j <= min(i, y); ++j)
            for (int k = 0; k < m; ++k) {
                dp[i + 1][j][k * 2 % m] += dp[i][j][k];
                dp[i][j + 1][(k * 2 + 1) % m] += dp[i][j][k];
            }
    for (int k = 0; k < m; ++k)
        ans += k * dp[x][y][k];
    cout << ans << endl;
}
