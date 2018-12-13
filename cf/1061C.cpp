#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87, C = 1e6 + 87, M = 1e9 + 7;
int dp[C];
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> d;
        int a;
        cin >> a;
        for (int j = 1; j * j <= a; ++j)
            if (a % j == 0) {
                d.push_back(j);
                if (a/j != j)
                    d.push_back(a/j);
            }
        sort(begin(d),end(d),greater<int>());
        for (int j : d) 
            dp[j] = (dp[j] + dp[j-1]) % M;
    }
    long long ans = -1;
    for (auto x : dp) ans += x;
    cout << ans % M << endl;
}
