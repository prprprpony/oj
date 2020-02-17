#include<bits/stdc++.h>
using namespace std;
const int N = 55, MOD = 998244353;
typedef long long ll;
ll inv(ll a)
{
    ll b = MOD - 2, r = 1;
    for ( ; b; b >>= 1, a = a * a % MOD)
        if (b & 1)
            r = r * a % MOD;
    return r;
}
int n;
ll l[N], r[N], dp[N][2 * N], ii[N];
int main()
{
    cin >> n;
    ll ot = 1;
    vector<ll> v = {-1};
    for (int i = n; i >= 1; --i) {
        cin >> l[i] >> r[i];
        ++r[i];
        ot = ot * (r[i] - l[i]) % MOD;
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(begin(v), end(v));
    v.resize(unique(begin(v), end(v)) - begin(v));
    int m = v.size() - 1;
    for (int i = 1; i <= n; ++i)
        ii[i] = inv(i);
    fill_n(dp[0], m, 1);
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j < m; ++j) {
            ll tl = v[j], tr = v[j + 1], hh = 1;
            ll tmw = tr - tl;
            for (ll k = 1, p = i; k <= i && l[p] <= tl && tr <= r[p]; ++k, --p) {
                hh = hh * (tmw + k - 1) % MOD * ii[k] % MOD; // h(tmw, k) = c(tmw + k - 1, k)
                (dp[i][j] += hh * dp[p - 1][j - 1]) %= MOD;
            }
            (dp[i][j] += dp[i][j - 1]) %= MOD;
        }
    }
    cout << dp[n][m - 1] * inv(ot) % MOD << endl;
}
