#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
int dp[N];
int main()
{
    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i-1];
        for (int k = 1; k <= i; k *= 6)
            dp[i] = min(dp[i],dp[i-k]);
        for (int k = 1; k <= i; k *= 9)
            dp[i] = min(dp[i],dp[i-k]);
        ++dp[i];
    }
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
