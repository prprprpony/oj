#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,M,D;
    cin >> n >> k >> M >> D;
    /*
     *  x <= M
     *  q = floor(n / x)
     *  p = ceil(q / k) <= D
     *  max{p * x}
     *
     *  given p
     *  q = kp - t, t = 0 to k-1
     *  n = xq + r, r = 0 to x-1
     */
    ll ans = 0;
    for (ll p = 1; p <= D; ++p) {
        ll lo = 1, hi = M, x;
        while (lo <= hi) {
            x = (lo + hi) / 2;
            if ((n / x + k - 1) / k >= p)
                lo = x + 1;
            else
                hi = x - 1;
        }
        x = hi;
        if (!x || (n / x + k - 1) / k != p)
            continue;
        ans = max(ans, p * x);
    }
    cout << ans << endl;
}
