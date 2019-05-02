#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5056, M = 998244353;
ll dp[N],a[N],inv[N];
int main()
{
    inv[1] = 1;
    for (int i = 2; i < N; ++i)
        inv[i] = (M-M/i)*inv[M%i]%M;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    dp[0] = 1;
    ll ans = 0;
    for (int x = 1; x <= n; ++x) {
        for (int i = n; i >= 0; --i) {
            if (a[x] >= 2 && i + 2 <= n)
                ans += dp[i] * a[x] % M * (a[x] - 1) % M * inv[n-i] % M * inv[n-i-1] % M;
            if (i >= 1)
                dp[i] = (dp[i] + dp[i-1] * a[x] % M * inv[n-i+1]) % M;
        }
    }
    cout << ans%M << endl;
}
