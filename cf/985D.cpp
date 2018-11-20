#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h;
ll f(ll x)
{
    if (x <= h) {
        return (1+x)*x/2;
    } else {
        return (h+x)*(x-h+1)/2 + (x-1)*x/2;
    }
}
int main()
{
    cin >> n >> h;
    ll lo = 1, hi = 1;
    while (f(hi) < n)
        hi <<= 1;
    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        if (f(mi) <= n)
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    for (ll x = hi-1; x<=hi+1 ; ++x) cerr << x << ' ' << f(x)<< ' ' << n-f(x) << endl;
    n -= f(hi);
    ll ans = hi <= h ? hi : hi*2-h;
    ans += (n+hi-1)/hi;
    cout << ans << endl;
}
