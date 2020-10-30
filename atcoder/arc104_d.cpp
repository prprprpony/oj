#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
const int C = N * (N - 1) / 2 * N;
int dp[N][C], su[N][C];
int n, k, MOD;
int main()
{
    cin >> n >> k >> MOD;
    dp[0][0] = 1;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 0; j < C; ++j) {
            su[i - 1][j] = (dp[i - 1][j] + (j >= i ? su[i - 1][j - i] : 0)) % MOD;
            dp[i][j] = (su[i - 1][j] - (j >= (k+1) * i ? su[i - 1][j - (k+1) * i] : 0) + MOD) % MOD;
        }
    }
    for (int x = 1; x <= n; ++x) {
        int a = n - x, b = x - 1;
        ll ans = MOD - 1;
        for (int j = 0; j < C; ++j)
            ans += dp[a][j] * 1ll * dp[b][j] % MOD * (k + 1) % MOD;
        cout << ans % MOD << '\n';
    }
}
