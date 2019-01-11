#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 16, M = 1e4+87, inf = 1e9 + 87;
int n,m,a[N][M];
int g[N][N];
int dp[1<<N][N];
void cal(int s)
{
    memset(dp,0,sizeof(dp));
    dp[1<<s][s] = inf;
    for (int S = 1; S < (1<<n); ++S)
        for (int j = 0; j < n; ++j)
            if (1<<j & S)
                for (int k = 0; k < n; ++k)
                    if (!(1<<k & S))
                        dp[1<<k|S][k] = max(dp[1<<k|S][k], min(dp[S][j], g[j][k]));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        int k = INT_MAX;
        for (int i = 1; i < m; ++i)
            k = min(k, abs(a[0][i] - a[0][i-1]));
        cout << k << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int w = INT_MAX;
            for (int k = 0; k < m; ++k)
                w = min(w, abs(a[i][k] - a[j][k]));
            g[i][j] = g[j][i] = w;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cal(i);
        for (int j = 0; j < n; ++j) if (i != j) {
            int w = INT_MAX;
            for (int k = 1; k < m; ++k)
                w = min(w, abs(a[i][k] - a[j][k-1]));
            ans = max(ans, min(w,dp[(1<<n)-1][j]));
        }
    }
    cout << ans << endl;
}
