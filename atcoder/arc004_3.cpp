#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x,y;
    char c;
    cin >> x >> c >> y;
    ll g = __gcd(x,y);
    x /= g, y /= g;
    ll t = 2*x/y;
    bool ok=false;
    for (ll n = t-1; n <= t+1; ++n) {
        if (n % y)
            continue;
        ll m = n * (n + 1) / 2 - n / y * x;
        if (1 <= m && m <= n) {
            ok = true;
            cout << n << ' ' << m << endl;
        }
    }
    if (!ok)
        cout << "Impossible\n";
}
