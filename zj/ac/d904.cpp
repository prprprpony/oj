#include <bits/stdc++.h>
using namespace std;
int coin[10];
int c, n;
int dp[1005];
const int inf = 100000;
int main()
{
    cin >> c >> n;
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    for (int i = 0; i <= c; i++)
        dp[i] = i % coin[0] == 0 ? i / coin[0] : inf;
    for (int i = 1; i < n; i++)
        for (int j = coin[i]; j <= c; j++)
            dp[j] = min(dp[j], 1 + dp[j-coin[i]]);
    cout << dp[c] << '\n';

    return 0;
}
