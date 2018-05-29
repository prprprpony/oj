#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define F first
#define S second
const int N = 1e5 + 987;
ll a[N];
ll n,m,k;
map<int,int> cnt;
ll inv(ll x)
{
    ll r = 1;
    for (int b = m - 2; b; b >>= 1, x = x * x % m)
        if (b & 1)
            r = r * x % m;
    return r;
}
ll cal(int l,int r)
{
    ll ans = 0;
    ll cur = 1;
    cnt.clear();
    ++cnt[1];
    for (int i = l; i < r; ++i) {
        (cur *= a[i]) %= m;
        ll t = inv(cur);
        ans += cnt[t * k % m];
        ++cnt[t];
    }
    return ans;
}
void solve()
{
    cin >> n >> m >> k;
    vector<int> sep;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if ((a[i] %= m) == 0)
            sep.push_back(i);
    }
    sep.push_back(n+1);
    if (k == 0) {
        ll ans = n * (n + 1) / 2;
        int la = 1;
        for (int i : sep) {
            ll w = i - la;
            ans -= w * (w + 1) / 2;
            la = i+1;
        }
        cout << ans << '\n';
    } else {
        ll ans = 0;
        int la = 1;
        for (int i : sep) {
            ans += cal(la,i);
            la = i+1;
        }
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
