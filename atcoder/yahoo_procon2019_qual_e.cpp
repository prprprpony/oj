#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 303, M = 998244353;
ll qpow(ll a,ll b)
{
    ll r = 1;
    for (;b;b>>=1,a=a*a%M)
        if (b & 1)
            r = r * a % M;
    return r;
}
bitset<N> a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            a[i][j] = x;
        }
    ll r = 0;
    for (ll i = 0; i < n; ++i) {
        ll j = a[i]._Find_first();
        if (j >= m)
            continue;
        ++r;
        for (ll k = i + 1; k < n; ++k)
            if (a[k][j])
                a[k] ^= a[i];
    }
    cout << (qpow(2,n) + M - qpow(2,n-r)) * qpow(2,m-1) % M << endl;
}
