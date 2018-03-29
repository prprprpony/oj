#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 87;
ll n,r,k,a[N],b[N];
bool ok(ll v)
{
    copy_n(a,n,b);
    int x = 0, y = 0;
    ll s = 0, t = k;
    for (int i = 0; i < n; ++i) {
        while (y <= min(i + r, n-1))
            s += b[y++];
        while (x < i-r)
            s -= b[x++];
        if (s < v) {
            ll w = v - s;
            t -= w;
            b[y-1] += w;
            s = v;
            if (t < 0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll lo = 0, hi = 2e18;
    while (lo <= hi) {
        ll mi = lo + hi >> 1;
        if (ok(mi))
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    cout << hi << endl;
}
