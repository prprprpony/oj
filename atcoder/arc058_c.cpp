#include<bits/stdc++.h>
using namespace std;
const int S = 17, N = 42, M = 1e9 + 7;
int dp[N][1<<S];
int main()
{
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    int s = x + y + z;
    int full = (1<<s) - 1;
    int hai = (1<<(x+y+z-1)) | (1<<(y+z-1)) | (1<<(z-1)); 
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= full; ++j) {
            for (int k = 1; k <= 10; ++k) {
                int w = ((j<<k) | (1<<(k-1))) & full;
                if ((w & hai) == hai)
                    continue;
                (dp[i+1][w] += dp[i][j]) %= M;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i)
        ans = 10LL * ans % M;
    for (int j = 0; j <= full; ++j)
        ans = (ans + M - dp[n][j]) % M;
    cout << ans << '\n';
}
