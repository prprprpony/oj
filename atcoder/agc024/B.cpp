#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 87;
int dp[N];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        ans = max(ans, dp[p] = dp[p-1] + 1);
    }
    cout << n - ans << endl;
}
