#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> ok(ll l,ll r,ll k)
{
    if (l > r) 
        return {-1,-1};
    for (ll i = 0; i <= k; ++i)
        if ((i+1)*i/2 <= r && (k+k-i+1)*i/2 >= l)
            return {i,max(l,(i+1)*i/2)};
    return {-1,-1};
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    ll hi = sqrt(2*(a+b)) + 87, lo = 0;
    while (lo <= hi) {
        ll k = (lo + hi) / 2;
        if (ok(k*(k+1)/2-b,a,k).first >= 0)
            lo = k + 1;
        else
            hi = k - 1;
    }
    ll k = hi, n, sa;
    tie(n,sa) = ok(k*(k+1)/2-b,a,k);
    set<ll> vis;
    cout << n << '\n';
    for (ll i = n; i >= 1; --i) {
        if (i < n)
            cout << ' ';
        ll d = i + min(sa - (i+1)*i/2, k - n);
        cout << d;
        vis.insert(d);
        sa -= d;
    }
    cout << '\n' << k - n << '\n';
    bool first = true;
    for (ll i = 1; i <= k; ++i) {
        if (!vis.count(i)) {
            if (first)
                first = false;
            else
                cout << ' ';
            cout << i;
        }
    }
    cout << '\n';
}
