#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
const char * t = "hard";
int n;
long long dp[N][4];
char s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> (s+1);
    dp[0][1] = dp[0][2] = dp[0][3] = 1e18;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j <= 3; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j && s[i] == t[j-1])
                dp[i][j] = min(dp[i][j],min(dp[i-1][j-1], dp[i-1][j]+a));
            if (s[i] == t[j])
                dp[i][j] += a;
//            cerr << i << ' ' << j << ' '<<dp[i][j]<<endl;
        }
    }
    cout << *min_element(dp[n],dp[n]+4) << endl;
}

